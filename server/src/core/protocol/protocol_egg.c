/*
** protocol_egg.c for protocol_egg in /home/antiqe/Documents/zappy/server/src/core/protocol
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Jul  9 18:21:23 2013 ronan guiho
** Last update Tue Jul  9 22:21:46 2013 ronan guiho
*/

#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "protocol.h"
#include "extend.h"
#include "level.h"

t_core g_core;

t_bool protocol_egg_hatching(t_egg *egg, t_player *to)
{
  t_action action;
  char buffer[512];

  bzero(buffer, 512);
  action.index = to->client->sock[TCP];
  action.ctime = to->ctime;
  sprintf(buffer, "eht %d\n", (int)egg->id);
  return (protocol_send(&g_core, &action, buffer));
}

t_bool protocol_egg_musty(t_egg *egg, t_player *to)
{
  t_action action;
  char buffer[512];

  bzero(buffer, 512);
  action.index = to->client->sock[TCP];
  action.ctime = to->ctime;
  sprintf(buffer, "edi %d\n", (int)egg->id);
  return (protocol_send(&g_core, &action, buffer));
}

void protocol_egg_hatching_notify(void *data, void *cntx)
{
  t_egg *egg;
  t_player *to;

  egg = (t_egg *)cntx;
  to = (t_player *)data;
  if (egg)
    protocol_egg_hatching(egg, to);
}

void protocol_egg_musty_notify(void *data, void *cntx)
{
  t_egg *egg;
  t_player *to;

  egg = (t_egg *)cntx;
  to = (t_player *)data;
  if (egg)
    protocol_egg_musty(egg, to);
}
