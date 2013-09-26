/*
** protocol_incantation_end.c for protocol_incantation_end in /home/antiqe/Documents/zappy/server/src/core/protocol
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Jul  9 18:45:57 2013 ronan guiho
** Last update Thu Jul 11 22:52:36 2013 alexis leprovost
*/

#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include <string.h>

#include "extend.h"
#include "protocol.h"
#include "protocol_incantation.h"

t_core g_core;

t_bool protocol_incantation_end(t_proto_inc *inc, t_player *to)
{
  t_action action;
  char buffer[512];

  bzero(buffer, 512);
  action.index = to->client->sock[TCP];
  action.ctime = to->ctime;
  sprintf(buffer, "pie %d %d %d\n", inc->x, inc->y, inc->res);
  return (protocol_send(&g_core, &action, buffer));
}

void protocol_incantation_end_notify(void *data, void *cntx)
{
  t_player *to;
  t_proto_inc *inc;

  to = (t_player *)data;
  inc = (t_proto_inc *)cntx;
  if (inc)
    protocol_incantation_end(inc, to);
}
