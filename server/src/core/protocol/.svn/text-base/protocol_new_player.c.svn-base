/*
** protocol_new_player.c for protocol_new_player in /home/antiqe/Documents/zappy/server/src/core/protocol
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Jul  9 13:01:35 2013 ronan guiho
** Last update Tue Jul  9 18:02:40 2013 ronan guiho
*/

#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "protocol.h"
#include "extend.h"
#include "level.h"

t_core g_core;

t_bool protocol_new_player(t_player *ref, t_player *to)
{
  t_action action;
  char buffer[512];

  bzero(buffer, 512);
  action.index = to->client->sock[TCP];
  action.ctime = to->ctime;
  sprintf(buffer, "pnw %d %d %d %d %d %s\n",
	  (int)ref->id, ref->x, ref->y, ref->direction, ref->level,
	  ref->team->name);
  return (protocol_send(&g_core, &action, buffer));
}

void protocol_newplayer_auth(void *data, void *cntx)
{
  t_player *player;
  t_player *to;

  to = (t_player *)cntx;
  player = (t_player *)data;
  if (player && player->type == BOT)
    protocol_new_player(player, to);
}

void protocol_newplayer_notify(void *data, void *cntx)
{
  t_player *player;
  t_player *to;

  player = (t_player *)cntx;
  to = (t_player *)data;
  if (player)
    protocol_new_player(player, to);
}
