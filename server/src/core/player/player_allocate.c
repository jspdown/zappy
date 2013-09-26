/*
** player_allocate.c for player_allocate in /home/antiqe/Documents/zappy/server/src/core/player
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Jun 18 16:06:16 2013 ronan guiho
** Last update Sat Jul 13 11:08:35 2013 alexis leprovost
*/

#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"
#include "list.h"
#include "ressource.h"
#include "core.h"
#include "stack.h"
#include "level.h"

t_core	g_core;

t_player *new_player()
{
  t_player *player;

  if ((player = malloc(sizeof(t_player))) == NULL)
    return (NULL);
  player->client = NULL;
  if (!g_core.pool->size(g_core.pool))
    g_core.pool->extend(g_core.pool, 1);
  player->id = g_core.pool->get(g_core.pool);
  player->x = -1;
  player->y = -1;
  player->level = ONE;
  player->direction = MAX_DIRECTION;
  bzero(player->inventory, sizeof(int) * MAX_RESSOURCE_TYPE);
  player->team = NULL;
  player->type = UNKNOWN;
  player->aggr = new_aggregator(strdup("\n"));
  time(&player->ctime);
  player->action = new_list();
  player->error = 0;
  if (!player->aggr || !player->id || !player->action)
    {
      delete_player(player);
      return (NULL);
    }
  return (player);
}

void delete_player(t_player *player)
{
  if (player)
    {
      if (player->client)
	{
	  player->client->disconnect(player->client);
	  delete_network_client(player->client);
	}
      if (player->aggr)
	delete_aggregator(player->aggr);
      if (player->action)
	delete_list(&player->action, NULL);
      g_core.pool->set(g_core.pool, player->id);
      free(player);
    }
}
