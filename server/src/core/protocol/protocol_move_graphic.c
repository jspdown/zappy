/*
** protocol_move_graphic.c for protocol_move_graphic in /home/antiqe/Documents/zappy/server/src/core/protocol
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Jul  9 14:26:36 2013 ronan guiho
** Last update Tue Jul  9 14:30:01 2013 ronan guiho
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

t_core g_core;

t_bool protocol_move_graphic(t_player *ref, t_player *to)
{
  t_action action;
  char buffer[512];

  bzero(buffer, 512);
  action.index = to->client->sock[TCP];
  action.ctime = to->ctime;
  sprintf(buffer, "ppo %d %d %d %d\n", (int)ref->id, ref->x,
	  ref->y, ref->direction);
  return (protocol_send(&g_core, &action, buffer));
}

void protocol_move_graphic_notify(void *data, void *cntx)
{
  t_player *player;
  t_player *ref;

  player = (t_player *)data;
  ref = (t_player *)cntx;
  if (player)
    protocol_move_graphic(ref, player);
}
