/*
** protocol_handle.c for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Jul  5 00:50:52 2013 alexis leprovost
** Last update Sat Jul 13 13:31:12 2013 alexis leprovost
*/

#include <stdlib.h>
#include <string.h>

#include "protocol.h"
#include "protocol_ressource.h"
#include "player.h"
#include "core.h"
#include "network/message/message.h"
#include "ressource.h"

static int	protocol_get_ressource(char* ressource)
{
  const size_t	len[MAX_RESSOURCE_TYPE] = { 10, 8, 9, 5, 8, 6, 8 };
  int	 i;

  i = -1;
  while (++i < MAX_RESSOURCE_TYPE)
    if (!strncmp(ressource, g_ressource_string[i], len[i]))
      return (i);
  return (MAX_RESSOURCE_TYPE);
}

t_bool protocol_take(t_core* c, t_player* player, t_action* action)
{
  char*	ressource;
  t_proto_res res;
  int	i;

  if (!protocol_stack(c, player) || player->type != BOT)
    return (protocol_send(c, action, "ko\n"));
  strtok((char*)action->data, " ");
  i = !(ressource = strtok(NULL, " ")) ? MAX_RESSOURCE_TYPE :
    protocol_get_ressource(ressource);
  if (i == MAX_RESSOURCE_TYPE ||
      !c->map->at(c->map, player->x, player->y)->ressources[i])
    return (protocol_send(c, action, "ko\n"));
  if (i == FOOD)
    map_generate_food(c->map, 1);
  --c->map->at(c->map, player->x, player->y)->ressources[i];
  ++player->inventory[i];
  res.player = player;
  res.res = i;
  res.action = TAKE;
  c->graphic->foreach2(c->graphic, protocol_ressource_act_notify, &res);
  return (protocol_send(c, action, "ok\n"));
}

t_bool protocol_drop(t_core* core, t_player* player, t_action* action)
{
  char*	ressource;
  t_proto_res res;
  int	i;

  if (!protocol_stack(core, player) || player->type != BOT)
    return (protocol_send(core, action, "ko\n"));
  strtok((char*)action->data, " ");
  if (!(ressource = strtok(NULL, " ")))
    i = MAX_RESSOURCE_TYPE;
  else
    i = protocol_get_ressource(ressource);
  if (i == MAX_RESSOURCE_TYPE || !player->inventory[i])
    return (protocol_send(core, action, "ko\n"));
  --player->inventory[i];
  ++core->map->at(core->map, player->x, player->y)->ressources[i];
  protocol_send(core, action, "ok\n");
  res.player = player;
  res.res = i;
  res.action = DROP;
  core->graphic->foreach2(core->graphic, protocol_ressource_act_notify, &res);
  if (i == FOOD && !player->inventory[i])
    protocol_spec(core, player, action);
  return (TRUE);
}
