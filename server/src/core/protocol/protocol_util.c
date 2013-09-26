/*
** protocol_util.c for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Jul  5 02:18:54 2013 alexis leprovost
** Last update Sat Jul 13 13:25:35 2013 alexis leprovost
*/

#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>

#include "protocol.h"
#include "extend.h"
#include "level.h"
#include "ressource.h"

t_bool protocol_pre_fork(t_core* core, t_player* player, t_action* action)
{
  t_action*	a;
  char		b[MAX_TEAM_NAME + 64];

  if (!protocol_stack(core, player) || player->type != BOT)
    return (protocol_send(core, action, "ko\n"));
  bzero(b, 64);
  sprintf(b, "%d %d %s", player->x, player->y, player->team->name);
  if (!(a = protocol_create(FORK, action->index, b, action->ctime)))
    return (protocol_send(core, action, "ko\n"));
  core->stack->set(core->stack, a);
  player->action->push_front(player->action, a);
  core->graphic->foreach2(core->graphic, protocol_fork_notify, player);
  return (TRUE);
}

t_bool protocol_connect_nbr(t_core* core, t_player* player, t_action* action)
{
  char	buff[32];

  if (!protocol_stack(core, player) || player->type != BOT)
    return (protocol_send(core, action, "ko\n"));
  bzero(buff, 32);
  if ((int)player->team->size < 0)
    sprintf(buff, "0\n");
  else
    sprintf(buff, "%ld\n", player->team->size);
  return (protocol_send(core, action, buff));
}

t_bool protocol_spec(t_core* core, t_player* player, t_action* action)
{
  protocol_send(core, action, "mort\n");
  core->graphic->foreach2(core->graphic, protocol_death_notify, player);
  player->action->__size__ = ACTION_MAX + 1;
  ++player->team->size;
  if (player->level == (MAX_LEVEL - 1))
    --player->team->max;
  return (TRUE);
}

t_bool protocol_death(t_core* c, t_player* player, t_action* action)
{
  if (!player || player->type != BOT || !action)
    return (TRUE);
  if (--player->inventory[FOOD] > 0)
    c->stack->set(c->stack, protocol_create(DEATH, action->index,
						  "", action->ctime));
  else
    if (!player->inventory[FOOD])
      {
	protocol_spec(c, player, action);
	map_generate_food(c->map, NB_FOOD);
	c->graphic->foreach(c->graphic, &protocol_data_map_notify);
      }
  return (TRUE);
}

t_bool protocol_disconnect(t_core* c, t_player* player, t_action* action)
{
  int		v[3];
  t_team*	team;
  t_player	splayer;

  (void)player;
  if (!action)
    return (TRUE);
  if ((team = (t_team*)c->team->find_if(c->team, strtok(action->data, " "),
					&protocol_find_team)))
    {
      v[0] = atoi(strtok(NULL, " "));
      v[1] = atoi(strtok(NULL, " "));
      v[2] = atoi(strtok(NULL, " "));
      if (v[2] > 0)
	{
	  ++team->size;
	  if (v[1] > (MAX_LEVEL - 1))
	    --team->max;
	  splayer.id = v[0];
	  c->graphic->foreach2(c->graphic, protocol_death_notify, &splayer);
	  map_generate_food(c->map, NB_FOOD);
	  c->graphic->foreach(c->graphic, &protocol_data_map_notify);
	}
    }
  return (TRUE);
}
