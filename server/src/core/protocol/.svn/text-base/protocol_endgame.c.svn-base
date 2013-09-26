/*
** protocol_endgame.c for protocol_endgame in /home/antiqe/Documents/zappy/server/src/core/protocol
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Jul  9 18:31:11 2013 ronan guiho
** Last update Thu Jul 11 14:39:57 2013 ronan guiho
*/

#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include <string.h>

#include "extend.h"
#include "protocol.h"
#include "protocol_incantation.h"

t_core g_core;

t_bool protocol_endgame(t_team *team, t_player *to)
{
  t_action action;
  char buffer[512];

  bzero(buffer, 512);
  action.index = to->client->sock[TCP];
  action.ctime = to->ctime;
  sprintf(buffer, "seg %s\n", team->name);
  return (protocol_send(&g_core, &action, buffer));
}

void protocol_endgame_notify(void *data, void *cntx)
{
  t_team *team;
  t_player *to;

  team = (t_team *)cntx;
  to = (t_player *)data;
  if (team)
    protocol_endgame(team, to);
}
