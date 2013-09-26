/*
** network_multiplexer_disconnect.c for network_multiplexer_disconnect in /home/antiqe/Documents/zappy/server/src/network
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Jul  8 10:22:27 2013 ronan guiho
** Last update Sat Jul 13 11:05:13 2013 alexis leprovost
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

void network_multiplexer_deleteclient_stack(t_player *player)
{
  char *trame;
  unsigned int size_team;

  if (player->team && player->team->name)
    {
      size_team = strlen(player->team->name);
      if ((trame = malloc(sizeof(char) * (size_team + 10))) != NULL)
	{
	  bzero(trame, size_team + 10);
	  sprintf(trame, "%s %d %d %d", player->team->name, (int)player->id,
		  player->level, player->inventory[FOOD]);
	  g_core.stack->set(g_core.stack,
			    protocol_create(DISCONNECT, -1, trame, (time_t)0));
	  free(trame);
	}
    }
}

void network_multiplexer_deleteclient_treatement(t_player *player)
{
  char buffer[256];
  t_log_message msg;

  if (g_core.network->list_client->size(g_core.network->list_client) == 0)
    g_core.network->max_fd = g_core.network->serv->sock[TCP] + 1;
  g_core.network->array_player[player->client->sock[TCP]] = NULL;
  bzero(buffer, 256);
  sprintf(buffer, "{%d} Disconnection of client on %s",
	  player->client->sock[TCP],
	  player->client->get_host(player->client));
  init_logging_message(&msg, "Network", buffer, INFORMATION);
  network_logging(g_core.network->log, &msg);
}

void network_multiplexer_deleteclient(t_player *player)
{
  int max;

  if (player && player->client)
    {
      FD_CLR(player->client->sock[TCP], &g_core.network->fdset);
      FD_CLR(player->client->sock[TCP], &g_core.network->wfdset);
      player->client->disconnect(player->client);
      g_core.network->list_client->
	erase(g_core.network->list_client, player, NULL);
      if (player->client->sock[TCP] == (g_core.network->max_fd - 1))
	{
	  max = g_core.network->serv->sock[TCP];
	  g_core.network->list_client->foreach2(g_core.network->list_client,
						network_mutiplexer_maxfd, &max);
	  g_core.network->max_fd = max + 1;
	}
      network_multiplexer_deleteclient_treatement(player);
      network_multiplexer_deleteclient_stack(player);
      if (player->type == GRAPHIC)
	g_core.graphic->erase(g_core.graphic, player, NULL);
      delete_player(player);
    }
}
