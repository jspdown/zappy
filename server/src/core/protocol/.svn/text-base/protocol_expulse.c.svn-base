/*
** protocol_expulse.c for protocol_expulse in /home/antiqe/Documents/zappy/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu Jul 11 13:50:32 2013 ronan guiho
** Last update Thu Jul 11 13:59:55 2013 ronan guiho
*/

#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include <string.h>

#include "extend.h"
#include "protocol.h"
#include "protocol_incantation.h"

t_core g_core;

t_bool protocol_expulse_graphic(t_player *player, t_player *to)
{
  t_action action;
  char buffer[512];

  bzero(buffer, 512);
  action.index = to->client->sock[TCP];
  action.ctime = to->ctime;
  sprintf(buffer, "pex %d\n", (int)player->id);
  return (protocol_send(&g_core, &action, buffer));
}

void protocol_expulse_notify(void *data, void *cntx)
{
  t_player *player;
  t_player *to;

  player = (t_player *)cntx;
  to = (t_player *)data;
  if (player)
    protocol_expulse_graphic(player, to);
}
