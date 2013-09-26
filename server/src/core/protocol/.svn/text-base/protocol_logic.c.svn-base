/*
** protocol_logic.c for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Jul  5 02:18:15 2013 alexis leprovost
** Last update Sat Jul 13 11:51:36 2013 alexis leprovost
*/

#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include <string.h>

#include "protocol_incantation.h"
#include "protocol_fork.h"
#include "protocol.h"
#include "extend.h"
#include "level.h"

t_bool protocol_incantation(t_core* core, t_player* player, t_action* action)
{
  t_action*	a;

  if (!protocol_stack(core, player) || player->type != BOT)
    return (protocol_send(core, action, "ko\n"));
  if (protocol_level(core, player))
    {
      if (!(a = protocol_create(ELEVATION, action->index, "", action->ctime)))
	return (protocol_send(core, action, "ko\n"));
      core->stack->set(core->stack, a);
      player->action->push_front(player->action, a);
      protocol_send(core, a, "elevation en cours\n");
      core->graphic->foreach2(core->graphic,
			      protocol_incantation_notify, player);
      return (TRUE);
    }
  return (protocol_send(core, action, "ko\n"));
}

t_bool protocol_elevation(t_core* core, t_player* p, t_action* action)
{
  t_up	up;
  t_proto_inc inc;

  if (!protocol_stack(core, p) || p->type != BOT)
    return (protocol_send(core, action, "ko\n"));
  inc.x = p->x;
  inc.y = p->y;
  if (protocol_level(core, p))
    {
      up.x = p->x;
      up.y = p->y;
      up.level = p->level;
      inc.res = 1;
      core->graphic->foreach2(core->graphic, protocol_incantation_end_notify,
			      &inc);
      core->graphic->foreach2(core->graphic, protocol_data_case_notify,
			      p);
      core->network->list_client->foreach2(core->network->list_client,
					   &protocol_up, (void*)&up);
      return (TRUE);
    }
  inc.res = 0;
  core->graphic->foreach2(core->graphic, protocol_incantation_end_notify,
			  &inc);
  return (protocol_send(core, action, "ko\n"));
}

t_bool protocol_fork(t_core* c, t_player* player, t_action* action)
{
  t_egg*	e;
  char		b[MAX_TEAM_NAME + 1];

  if (!protocol_stack(c, player) || player->type != BOT ||
      !(e = malloc(sizeof(t_egg))))
    return (protocol_send(c, action, "ko\n"));
  e->x = atoi(strtok((char*)action->data, " "));
  e->y = atoi(strtok(NULL, " "));
  e->team = c->team->find_if(c->team, strtok(NULL, " "), &protocol_find_team);
  e->id = c->pool->get(c->pool);
  e->player = player;
  if (!e->id)
    {
      c->pool->extend(c->pool, 1);
      free(e);
      return (protocol_send(c, action, "ko\n"));
    }
  bzero(b, MAX_TEAM_NAME + 1);
  sprintf(b, "%s", e->team->name);
  c->stack->set(c->stack,
		protocol_create(ECLOSION, action->index, b, action->ctime));
  c->egg->push_back(c->egg, (void*)e);
  c->graphic->foreach2(c->graphic,
			  protocol_endfork_notify, e);
  return (protocol_send(c, action, "ok\n"));
}

t_bool protocol_eclosion(t_core* core, t_player* player, t_action* action)
{
  t_egg*	egg;

  if (!player || player->type != BOT || !action ||
      !(egg = core->egg->find_if(core->egg, action->data, &protocol_find_egg)))
    return (TRUE);
  ++egg->team->size;
  core->stack->set(core->stack,
		   protocol_create(CORRUPT, action->index, action->data,
				   action->ctime));
  return (TRUE);
}

t_bool protocol_win(t_core* core, t_player* player, t_action* action)
{
  (void)action;
  if (!player || !player->type != BOT || !action)
    return (TRUE);
  core->state = FALSE;
  core->graphic->foreach2(core->graphic, protocol_endgame_notify,
			  player->team);
  return (TRUE);
}
