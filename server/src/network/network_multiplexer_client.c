/*
** network_multiplexer_client.c for network_multiplexer_client in /home/antiqe/Documents/zappy/server/src/network
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri Jun 14 14:16:33 2013 ronan guiho
** Last update Sat Jul 13 10:56:43 2013 alexis leprovost
*/

#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/resource.h>

#include "core/core.h"
#include "core/ressource/ressource.h"
#include "network/network.h"
#include "core/stack/action.h"
#include "core/player/player.h"
#include "network/message/message.h"
#include "core/protocol/protocol.h"

t_core g_core;

void network_mutiplexer_maxfd(void *data, void *cntx)
{
  int *max;
  t_player *player;

  (void)cntx;
  player = (t_player *)data;
  max = (int *)cntx;
  if (player)
    {
      if (player->client->sock[TCP] >= *max)
	*max = player->client->sock[TCP];
    }
}

void network_multiplexer_issetclient(void *data, void *set)
{
  int ret;
  fd_set *fdset;
  t_player *player;
  char buffer[513];

  fdset = (fd_set *)set;
  player = (t_player *)data;
  if (FD_ISSET(player->client->sock[TCP], fdset))
    {
      if ((ret = player->client->receive(player->client, buffer, 512)) == 0)
	network_multiplexer_deleteclient(player);
      else if (ret > 0 && ret <= 512)
	{
	  buffer[ret] = '\0';
	  player->aggr->push(player->aggr,
			     new_message(player->client->sock[TCP], buffer));
	}
    }
}
