/*
** protocol_fork.c for protocol_fork in /home/antiqe/Documents/zappy/server/src/core/protocol
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Jul  9 17:56:37 2013 ronan guiho
** Last update Thu Jul 11 15:44:14 2013 alexis leprovost
*/

#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include <string.h>

#include "extend.h"
#include "protocol.h"
#include "protocol_fork.h"
#include "protocol_incantation.h"

t_core g_core;

t_bool protocol_fork_graphic(t_player *ref, t_player *to)
{
  t_action action;
  char buffer[512];

  bzero(buffer, 512);
  action.index = to->client->sock[TCP];
  action.ctime = to->ctime;
  sprintf(buffer, "pfk %d\n", (int)ref->id);
  return (protocol_send(&g_core, &action, buffer));
}

t_bool protocol_endfork_graphic(t_egg *egg, t_player *to)
{
  t_action action;
  char buffer[512];

  bzero(buffer, 512);
  action.index = to->client->sock[TCP];
  action.ctime = to->ctime;
  sprintf(buffer, "enw %d %d %d %d\n",
	  (int)egg->id, (int)egg->player->id, egg->player->x,
	  egg->player->y);
  return (protocol_send(&g_core, &action, buffer));
}

void protocol_endfork_notify(void *data, void *cntx)
{
  t_egg *egg;
  t_player *to;

  egg = (t_egg *)cntx;
  to = (t_player *)data;
  if (egg)
    protocol_endfork_graphic(egg, to);
}

void protocol_fork_notify(void *data, void *cntx)
{
  t_player *player;
  t_player *to;

  player = (t_player *)cntx;
  to = (t_player *)data;
  if (player)
    protocol_fork_graphic(player, to);
}
