/*
** protocol_broadcast.c for protocol_broadcast in /home/antiqe/Documents/zappy/server/src/core/protocol
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Jul  9 16:57:09 2013 ronan guiho
** Last update Thu Jul 11 23:10:44 2013 alexis leprovost
*/

#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "protocol_broadcast.h"
#include "protocol.h"
#include "extend.h"
#include "level.h"

t_core g_core;

t_bool protocol_broadcast_graphic(t_proto_broad *broad, t_player *to)
{
  t_action action;
  char buffer[512];

  action.index = to->client->sock[TCP];
  action.ctime = to->ctime;
  bzero(buffer, 512);
  sprintf(buffer, "pbc %d %s", broad->id, broad->msg);
  return (protocol_send(&g_core, &action, buffer));
}

void protocol_broadcast_notify(void *data, void *cntx)
{
  t_proto_broad *broad;
  t_player *to;

  broad = (t_proto_broad *)cntx;
  to = (t_player *)data;
  if (broad)
    protocol_broadcast_graphic(broad, to);
}
