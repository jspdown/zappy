/*
** protocol_death.c for protocol_death in /home/antiqe/Documents/zappy/server/src/core/protocol
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Jul  9 18:11:44 2013 ronan guiho
** Last update Thu Jul 11 15:44:36 2013 alexis leprovost
*/

#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include <string.h>

#include "extend.h"
#include "protocol.h"
#include "protocol_incantation.h"

t_core g_core;

t_bool protocol_death_graphic(t_player *ref, t_player *to)
{
  t_action action;
  char buffer[512];

  bzero(buffer, 512);
  action.index = to->client->sock[TCP];
  action.ctime = to->ctime;
  sprintf(buffer, "pdi %d\n", (int)ref->id);
  return (protocol_send(&g_core, &action, buffer));
}

void protocol_death_notify(void *data, void *cntx)
{
  t_player *player;
  t_player *to;

  player = (t_player *)cntx;
  to = (t_player *)data;
  if (player)
    protocol_death_graphic(player, to);
}
