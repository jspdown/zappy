/*
** protocol_sync.c for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Jul  5 00:50:52 2013 alexis leprovost
** Last update Sat Jul 13 13:05:45 2013 alexis leprovost
*/

#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "protocol.h"
#include "player.h"
#include "core.h"
#include "team.h"
#include "network/message/message.h"
#include "ressource.h"

static t_bool	protocol_sync_graphic(t_core* core, t_player* player,
				      t_action* action)
{
  player->type = GRAPHIC;
  core->graphic->push_front(core->graphic, player);
  protocol_map_size(core, player, action);
  protocol_get_time(core, player, action);
  protocol_data_map(core, player, action);
  protocol_get_team(core, player, action);
  core->network->list_client->foreach2(core->network->list_client,
				       protocol_newplayer_auth, player);
  core->egg->foreach2(core->egg, protocol_egg_waslaid_auth, player);
  return (TRUE);
}

static void	protocol_sync_bot_from_egg(t_core* core, t_player* player,
					   t_egg* egg)
{
  player->team = egg->team;
  player->x = egg->x;
  player->y = egg->y;
  player->direction = (rand() % WEST) + 1;
  player->inventory[FOOD] = 10;
  player->type = BOT;
  core->pool->set(core->pool, egg->id);
  core->graphic->foreach2(core->graphic, protocol_egg_newplayer_notify, egg);
  core->egg->erase(core->egg, (void*)egg, &free);
}

static void	protocol_sync_bot_from_team(t_core* core, t_player* player,
					      t_team* team)
{
  player->team = team;
  player->x = rand() % core->map->width(core->map);
  player->y = rand() % core->map->height(core->map);
  player->direction = (rand() % WEST) + 1;
  player->inventory[FOOD] = 10;
  player->type = BOT;
}

static t_bool	protocol_sync_bot(t_core* c, t_player* player,
				  t_action* action)
{
  t_team*	team;
  char		buff[64];
  t_egg*	egg;

  ((char *)action->data)[strlen((char *)action->data) - 1] = '\0';
  team = (t_team*)c->team->find_if(c->team,
				      action->data, &protocol_find_team);
  if (!team || team->size < 1)
    return (protocol_send(c, action, "ko\n"));
  bzero(buff, 64);
  --team->size;
  sprintf(buff, "%ld\n", team->size);
  protocol_send(c, action, buff);
  if ((egg = c->egg->find_if(c->egg, (void*)team->name, &protocol_find_egg)))
    protocol_sync_bot_from_egg(c, player, egg);
  else
    protocol_sync_bot_from_team(c, player, team);
  ++c->map->at(c->map, player->x, player->y)->players;
  bzero(buff, 32);
  sprintf(buff, "%ld %ld\n", c->map->__width__, c->map->__height__);
  protocol_send(c, action, buff);
  c->stack->set(c->stack, protocol_create(DEATH, action->index,
						"", action->ctime));
  c->graphic->foreach2(c->graphic, protocol_newplayer_notify, player);
  return (TRUE);
}

t_bool protocol_sync(t_core* core, t_player* player, t_action* action)
{
  if (!protocol_stack(core, player) || player->type != UNKNOWN ||
      !(action->data = (void*)strtok((char*)action->data, " ")))
    return (protocol_send(core, action, "ko\n"));
  if (!strcmp((char*)action->data, "GRAPHIC\n"))
    return (protocol_sync_graphic(core, player, action));
  return (protocol_sync_bot(core, player, action));
}
