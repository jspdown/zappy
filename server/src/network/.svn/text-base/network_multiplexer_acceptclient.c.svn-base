/*
** network_multiplexer_client.c for network_multiplexer_client in /home/antiqe/Documents/zappy/server/src/network
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri Jun 14 14:16:33 2013 ronan guiho
** Last update Thu Jul 11 22:04:55 2013 ronan guiho
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

t_core g_core;

void network_multiplexer_acceptclient_net(t_player *player,
					  t_client *client)
{
  char buffer[256];
  t_log_message msg;

  bzero(buffer, 256);
  player->client = client;
  g_core.network->max_fd = (g_core.network->max_fd <= client->sock[TCP]) ?
    (client->sock[TCP] + 1) : g_core.network->max_fd;
  FD_SET(client->sock[TCP], &g_core.network->fdset);
  FD_SET(client->sock[TCP], &g_core.network->wfdset);
  sprintf(buffer, "{%d} Connection of client on %s", client->sock[TCP],
	  client->get_host(client));
  init_logging_message(&msg, "Network", buffer, INFORMATION);
  network_logging(g_core.network->log, &msg);
  g_core.network->list_client->push_front(g_core.network->list_client, player);
  if (client->sock[TCP] >= (int)g_core.network->array_player_size)
    {
      g_core.network->array_player_size *= 2;
      g_core.network->array_player = realloc(g_core.network->array_player,
					     sizeof(t_player *) *
					     g_core.network->array_player_size);
    }
  g_core.network->array_player[client->sock[TCP]] = player;
  g_core.network->send_queue->push_back(g_core.network->send_queue,
					new_message(client->sock[TCP], "BIENVENUE\n"));
}

void network_multiplexer_acceptclient(t_network *network)
{
  t_client *client;
  t_player *player;
  struct rlimit limit;

  getrlimit(RLIMIT_NOFILE, &limit);
  if ((client = network->serv->accept_connect(network->serv)) != NULL)
    {
      if ((network->max_fd + 1) < (int)limit.rlim_cur)
	{
	  if ((player = new_player()) != NULL)
	    network_multiplexer_acceptclient_net(player, client);
	}
      else
	{
	  client->disconnect(client);
	  delete_network_client(client);
	}
    }
}
