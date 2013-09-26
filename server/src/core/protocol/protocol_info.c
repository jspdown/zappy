/*
** protocol_info.c for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Jul  5 02:14:39 2013 alexis leprovost
** Last update Sat Jul 13 13:00:53 2013 alexis leprovost
*/

#include <stdlib.h>
#include <strings.h>
#include <stdio.h>

#include "protocol.h"
#include "extend.h"
#include "ressource.h"

t_bool protocol_see(t_core* core, t_player* player, t_action* action)
{
  char *view;

  if (!protocol_stack(core, player) || player->type != BOT)
    return (protocol_send(core, action, "ko\n"));
  view = player_view(player);
  protocol_send(core, action, view);
  free(view);
  return (TRUE);
}

t_bool protocol_inventory(t_core* core, t_player* player, t_action* action)
{
  char	buffer[512];

  if (!protocol_stack(core, player) || player->type != BOT)
    return (protocol_send(core, action, "ko\n"));
  bzero(buffer, 512);
  sprintf(buffer, "{%s %d,%s %d,%s %d,%s %d,%s %d,%s %d,%s %d}\n",
	  g_ressource_string[FOOD], player->inventory[FOOD],
	  g_ressource_string[LINEMATE], player->inventory[LINEMATE],
	  g_ressource_string[DERAUMERE], player->inventory[DERAUMERE],
	  g_ressource_string[SIBUR], player->inventory[SIBUR],
	  g_ressource_string[MENDIANE], player->inventory[MENDIANE],
	  g_ressource_string[PHIRAS], player->inventory[PHIRAS],
	  g_ressource_string[THYSTAME], player->inventory[THYSTAME]);
  return (protocol_send(core, action, buffer));
}

t_bool protocol_corrupt(t_core* core, t_player* player, t_action* action)
{
  t_egg*	egg;

  if (!action)
    return (TRUE);
  (void)player;
  egg = (t_egg*)core->egg->find_if(core->egg,
				   action->data,
				   &protocol_find_egg);
  if (egg)
    {
      core->graphic->foreach2(core->graphic, protocol_egg_musty_notify,
			      egg);
      core->pool->set(core->pool, egg->id);
      core->egg->erase(core->egg, egg, &free);
    }
  return (TRUE);
}

int	protocol_count_player(void* d1, void* d2)
{
  t_player*	p1;
  t_player*	p2;

  p1 = (t_player*)d1;
  p2 = (t_player*)d2;
  if (p1 && p2 && p1->type == BOT && p2->type == BOT &&
      p1->level == p2->level && p1->x == p2->x &&
      p1->y == p2->y)
    return (1);
  return (0);
}
