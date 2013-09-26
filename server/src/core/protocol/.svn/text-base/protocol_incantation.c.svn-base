/*
** protocol_incantation.c for protocol_incantation in /home/antiqe/Documents/zappy/server/src/core/protocol
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Jul  9 16:59:14 2013 ronan guiho
** Last update Thu Jul 11 15:55:53 2013 alexis leprovost
*/

#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include <string.h>

#include "extend.h"
#include "protocol.h"
#include "protocol_incantation.h"

t_core g_core;

void   protocol_get_player_by_pos(void *data, void *cntx)
{
  char buffer[64];
  t_player *player;
  t_proto_inc *inc;

  player = (t_player *)data;
  inc = (t_proto_inc *)cntx;
  if (player->x == (int)inc->x && player->y == (int)inc->y &&
      (int)inc->id != (int)player->id)
    {
      if ((inc->buffer = realloc(inc->buffer, sizeof(char) * inc->size)) \
	  != NULL)
	{
	  bzero(buffer, 64);
	  bzero(&inc->buffer[inc->size - 32], 32);
	  inc->size *= 2;
	  sprintf(buffer, " %d", (int)player->id);
	  strcat(inc->buffer, buffer);
	}
    }
}

static void	protocol_incantation_init_graphic(t_player* ref,
						  t_proto_inc* inc)
{
  inc->x = ref->x;
  inc->y = ref->y;
  inc->size = 32;
  inc->id = ref->id;
  inc->buffer = NULL;
}

t_bool protocol_incantation_graphic(t_player *ref, t_player *to)
{
  char *trame;
  char buffer[128];
  t_action action;
  t_proto_inc inc;

  protocol_incantation_init_graphic(ref, &inc);
  action.index = to->client->sock[TCP];
  action.ctime = to->ctime;
  bzero(buffer, 128);
  sprintf(buffer, "pic %d %d %d %d", ref->x, ref->y, ref->level, (int)ref->id);
  g_core.network->list_client->foreach2(g_core.network->list_client,
					protocol_get_player_by_pos,
					&inc);
  if ((trame = malloc(sizeof(char) * (strlen(buffer)			\
				      + (!inc.buffer ? 2 :		\
					 strlen(inc.buffer)) + 3))) == NULL)
    return (FALSE);
  bzero(trame, strlen(buffer) + (!inc.buffer ? 2 : strlen(inc.buffer)) + 3);
  if (inc.buffer)
    sprintf(trame, "%s%s\n", buffer, inc.buffer);
  else
    sprintf(trame, "%s\n", buffer);
  protocol_send(&g_core, &action, trame);
  free(trame);
  return (TRUE);
}

void protocol_incantation_notify(void *data, void *cntx)
{
  t_player *player;
  t_player *to;

  player = (t_player *)cntx;
  to = (t_player *)data;
  if (player)
    protocol_incantation_graphic(player, to);
}
