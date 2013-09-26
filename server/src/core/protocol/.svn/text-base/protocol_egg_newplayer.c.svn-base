/*
** protocol_egg.c for protocol_egg in /home/antiqe/Documents/zappy/server/src/core/protocol
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Jul  9 13:36:14 2013 ronan guiho
** Last update Tue Jul  9 14:29:01 2013 ronan guiho
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

t_bool protocol_egg_newplayer(t_egg *egg, t_player *to)
{
  t_action action;
  char buffer[512];

  bzero(buffer, 512);
  action.index = to->client->sock[TCP];
  action.ctime = to->ctime;
  sprintf(buffer, "ebo %d\n", (int)egg->id);
  return (protocol_send(&g_core, &action, buffer));
}

void protocol_egg_newplayer_notify(void *data, void *cntx)
{
  t_player *player;
  t_egg *egg;

  player = (t_player *)data;
  egg = (t_egg *)cntx;
  if (player)
    protocol_egg_newplayer(egg, player);
}
