/*
** protocol_ressource.c for protocol_ressource in /home/antiqe/Documents/zappy/server/src/core/protocol
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Jul  9 16:16:16 2013 ronan guiho
** Last update Wed Jul 10 11:10:54 2013 ronan guiho
*/

#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "protocol_ressource.h"
#include "protocol.h"
#include "extend.h"
#include "level.h"

t_core g_core;

t_bool protocol_ressource_take(t_proto_res *res, t_player *to)
{
  t_action action;
  char buffer[512];

  bzero(buffer, 512);
  action.index = to->client->sock[TCP];
  action.ctime = to->ctime;
  sprintf(buffer, "pgt %d %d\n", (int)res->player->id, res->res);
  return (protocol_send(&g_core, &action, buffer));
}

t_bool protocol_ressource_drop(t_proto_res *res, t_player *to)
{
  t_action action;
  char buffer[512];

  bzero(buffer, 512);
  action.index = to->client->sock[TCP];
  action.ctime = to->ctime;
  sprintf(buffer, "pdr %d %d\n", (int)res->player->id, res->res);
  return (protocol_send(&g_core, &action, buffer));
}

t_bool protocol_ressource_take_case(t_player *ref, t_action *action)
{
  char buffer[512];
  unsigned int pos[2];

  pos[0] = ref->x;
  pos[1] = ref->y;
  bzero(buffer, 512);
  protocol_get_case(buffer, pos);
  return (protocol_send(&g_core, action, buffer));
}

void protocol_ressource_act_notify(void *data, void *cntx)
{
  t_player *to;
  t_action action;
  t_proto_res *res;

  res = (t_proto_res *)cntx;
  to = (t_player *)data;
  if (res)
    {
      action.index = to->client->sock[TCP];
      action.ctime = to->ctime;
      (res->action == TAKE) ? protocol_ressource_take(res, to) :
	protocol_ressource_drop(res, to);
      protocol_data_player_aux(res->player, to);
      protocol_ressource_take_case(res->player, &action);
    }
}
