/*
** protocol_move.c for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Jul  5 00:50:52 2013 alexis leprovost
** Last update Sat Jul 13 13:04:57 2013 alexis leprovost
*/

#include <stdlib.h>

#include "protocol.h"
#include "player.h"
#include "core.h"
#include "network/message/message.h"

t_bool protocol_move(t_core* core, t_player* player, t_action* action)
{
  const char	move[MAX_DIRECTION][2] = {
    {0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1}
  };

  if (!protocol_stack(core, player) || player->type != BOT)
    return (protocol_send(core, action, "ko\n"));
  --core->map->at(core->map, player->x, player->y)->players;
  player->y += move[player->direction][0];
  if (player->y >= (int)core->map->height(core->map))
    player->y = 0;
  if (player->y < 0)
    player->y = core->map->height(core->map) - 1;
  player->x += move[player->direction][1];
  if (player->x >= (int)core->map->width(core->map))
    player->x = 0;
  if (player->x < 0)
    player->x = core->map->width(core->map) - 1;
  ++core->map->at(core->map, player->x, player->y)->players;
  core->graphic->foreach2(core->graphic, protocol_move_graphic_notify, player);
  return (protocol_send(core, action, "ok\n"));
}

t_bool protocol_left(t_core* core, t_player* player, t_action* action)
{
  const char	rot[MAX_DIRECTION] = {0, WEST, NORTH, EAST, SOUTH};

  if (!protocol_stack(core, player) || player->type != BOT)
    return (protocol_send(core, action, "ko\n"));
  player->direction = rot[player->direction];
  core->graphic->foreach2(core->graphic, protocol_move_graphic_notify, player);
  return (protocol_send(core, action, "ok\n"));
}

t_bool protocol_right(t_core* core, t_player* player, t_action* action)
{
  const char	rot[MAX_DIRECTION] = {0, EAST, SOUTH, WEST, NORTH};

  if (!protocol_stack(core, player) || player->type != BOT)
    return (protocol_send(core, action, "ko\n"));
  player->direction = rot[player->direction];
  core->graphic->foreach2(core->graphic, protocol_move_graphic_notify, player);
  return (protocol_send(core, action, "ok\n"));
}
