/*
** protocol_physic.c for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Jul  5 02:17:30 2013 alexis leprovost
** Last update Thu Jul 11 23:08:30 2013 alexis leprovost
*/

#include <stdlib.h>
#include <string.h>

#include "protocol.h"
#include "extend.h"
#include "protocol_broadcast.h"

t_bool protocol_expulse(t_core* core, t_player* player, t_action* action)
{
  t_broadcast	broad;

  if (!protocol_stack(core, player) || player->type != BOT ||
      (!(broad.message = malloc(sizeof(char) * 16))))
    return (protocol_send(core, action, "ko\n"));
  bzero(broad.message, 16);
  broad.player = player;
  sprintf(broad.message, "deplacement,  \n");
  core->network->list_client->foreach2(core->network->list_client,
				       &protocol_do_expulse,
				       (void*)&broad);
  free(broad.message);
  return (protocol_send(core, action, "ok\n"));
}

t_bool protocol_broadcast(t_core* core, t_player* player, t_action* action)
{
  t_broadcast	broad;
  size_t	len;
  t_proto_broad b;

  if (!protocol_stack(core, player) || player->type != BOT ||
      g_proto[BROADCAST].size + 2 >= strlen((char*)action->data))
    return (protocol_send(core, action, "ko\n"));
  len = strlen(&((char*)action->data)[g_proto[BROADCAST].size + 1]) + 13;
  if (!(broad.message = malloc(sizeof(char) * len)))
    return (protocol_send(core, action, "ko\n"));
  bzero(broad.message, len);
  broad.player = player;
  sprintf(broad.message, "message  ,%s",
	  &((char*)action->data)[g_proto[BROADCAST].size + 1]);
  core->network->list_client->foreach2(core->network->list_client,
				       &protocol_do_broadcast,
				       (void*)&broad);
  b.id = broad.player->id;
  b.msg = broad.message;
  core->graphic->foreach2(core->graphic, protocol_broadcast_notify,
			  &b);
  free(broad.message);
  return (protocol_send(core, action, "ok\n"));
}
