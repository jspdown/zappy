/*
** protocol_egglaid.c for protocol_egglaid in /home/antiqe/Documents/zappy/server/src/core/protocol
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Jul  9 14:02:01 2013 ronan guiho
** Last update Tue Jul  9 17:06:44 2013 ronan guiho
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

t_bool protocol_egg_waslaid(t_egg *egg, t_player *to)
{
  t_action action;
  char buffer[512];

  bzero(buffer, 512);
  action.index = to->client->sock[TCP];
  action.ctime = to->ctime;
  sprintf(buffer, "enw %d %d %d %d\n", (int)egg->id, (int)egg->player->id,
	  egg->x, egg->y);
  return (protocol_send(&g_core, &action, buffer));
}

void protocol_egg_waslaid_auth(void *data, void *cntx)
{
  t_egg *egg;
  t_player *to;

  to = (t_player *)cntx;
  egg = (t_egg *)data;
  if (egg)
    protocol_egg_waslaid(egg, to);
}
