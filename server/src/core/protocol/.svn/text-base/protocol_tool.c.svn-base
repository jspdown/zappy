/*
** protocol_tool.c for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Jul  5 12:04:12 2013 alexis leprovost
** Last update Fri Jul 12 17:19:15 2013 alexis leprovost
*/

#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "protocol.h"
#include "core.h"
#include "team.h"
#include "ressource.h"
#include "level.h"

t_core	g_core;

int	protocol_find_egg(void* d1, void* d2)
{
  t_egg*	egg;
  char*		name;

  egg = (t_egg*)d1;
  name = (char*)d2;
  if (!egg || !name)
    return (0);
  return (!strcmp(egg->team->name, name));
}

int	protocol_find_team(void* d1, void* d2)
{
  char*		name;
  t_team*	team;

  name = (char*)d2;
  team = (t_team*)d1;
  if (!d1 || !d2)
    return (0);
  return (!strcmp(name, team->name));
}

t_bool	protocol_stack(t_core* core, t_player* player)
{
  if (!player)
    return (FALSE);
  player->action->pop_front(player->action);
  if (!player->action->empty(player->action))
    core->stack->set(core->stack, player->action->front(player->action));
  return (TRUE);
}

t_bool	protocol_level(t_core* core, t_player* player)
{
  int		i;
  size_t	n;
  t_cell*	cell;

  if (player->level == MAX_LEVEL - 1)
    return (FALSE);
  i = 0;
  cell = core->map->at(core->map, player->x, player->y);
  while (++i < MAX_RESSOURCE_TYPE)
    if (cell->ressources[i] != g_level[(int)player->level].ressources[i])
      return (FALSE);
  n = core->network->list_client->map2(core->network->list_client,
				       &protocol_count_player, (void*)player);
  return (n == g_level[(int)player->level].players && n == cell->players);
}

void    protocol_up(void* d1, void* d2)
{
  t_player*	p;
  t_up*		up;
  t_action	action;
  char		buffer[21];

  p = (t_player*)d1;
  up = (t_up*)d2;
  if (p && p->type == BOT && up && p->x == up->x && p->y == up->y &&
      p->level == up->level)
    {
      bzero(buffer, 20);
      action.index = p->client->sock[TCP];
      action.ctime = p->ctime;
      sprintf(buffer, "niveau actuel : %d\n", ++p->level);
      if (p->level == MAX_LEVEL)
	++p->team->max;
      if (p->team->max == g_core.max)
	g_core.stack->set(g_core.stack,
			  protocol_create(WIN, p->client->sock[TCP], "",
					  p->ctime));
      g_core.graphic->foreach2(g_core.graphic, protocol_level_player_notify,
			       p);
      protocol_send(&g_core, &action, buffer);
    }
}
