/*
** player_view.c for player_view in /home/antiqe/Documents/zappy/server/src/core/player
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Jul  2 14:26:58 2013 ronan guiho
** Last update Sat Jul 13 12:36:36 2013 alexis leprovost
*/

#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"
#include "list.h"
#include "ressource.h"
#include "core.h"

t_core g_core;
const char* g_ressource_string[MAX_RESSOURCE_TYPE];

const t_view ref_view[] = {
  {0, 0, 0, 0},
  {-1, -1, 1, 0},
  {1, -1, 1, 1},
  {1, 1, -1, 0},
  {-1, 1, -1, 1}
};

void player_view_move(t_player *player, int *pos, int *ini,
		      int i)
{
  pos[0] = ((i != 0) ? ini[0] : pos[0]) + ref_view[player->direction].x;
  pos[1] = ((i != 0) ? ini[1] : pos[1]) + ref_view[player->direction].y;
  player_view_limit(pos);
  ini[0] = pos[0];
  ini[1] = pos[1];
}

void player_view_buffer_ressource(t_cell *cell, char **trame, int *allocate)
{
  int i;
  int i1;

  i = -1;
  while (++i < MAX_RESSOURCE_TYPE)
    {
      if ((int)cell->ressources[i] != 0)
	if ((*trame = realloc(*trame,
			      sizeof(char)				\
			      * (*allocate				\
				 + ((int)cell->ressources[i] * 20)))) != NULL)
	  {
	    i1 = -1;
	    bzero(&(*trame)[*allocate - 1], ((int)cell->ressources[i] * 20));
	    while (++i1 < (int)cell->ressources[i])
	      {
		strcat(*trame, " ");
		strcat(*trame, g_ressource_string[i]);
	      }
	    *allocate += ((int)cell->ressources[i] * 20);
	  }
    }
}

void player_view_buffer(t_cell *cell, char **trame, int *allocate)
{
  int i;

  if ((int)cell->players > 0)
    {
      if ((*trame = realloc(*trame, sizeof(char) *
			    (*allocate + (8 * (int)cell->players)))) != NULL)
	{
	  i = -1;
	  bzero(&((*trame)[*allocate - 1]), (8 * (int)cell->players));
	  while (++i < (int)cell->players)
	    strcat(*trame, " joueur");
	  *allocate += (8 * (int)cell->players);
	}
    }
  player_view_buffer_ressource(cell, trame, allocate);
}

void player_view_init(t_player *player, int *pos, int *ini,
		      int *ref)
{
  ref[2] = (3 * player->level) + (player->level * (player->level - 1));
  ref[0] = 0;
  ref[1] = 3;
  ini[0] = 0;
  ini[1] = 0;
  pos[0] = player->x;
  pos[1] = player->y;
}

char *player_view(t_player *player)
{
  int ref[3];
  int pos[2];
  int ini[3];
  t_cell *cell;
  char *trame;
  int allocate;

  ini[2] = -1;
  player_view_init(player, pos, ini, ref);
  allocate = 5 + ref[2];
  if ((trame = malloc(sizeof(char) * (allocate))) == NULL)
    return (NULL);
  bzero(trame, allocate);
  trame[0] = '{';
  while (++ini[2] <= ref[2])
    {
      if ((cell = g_core.map->at(g_core.map, pos[0], pos[1])) != NULL)
	player_view_buffer(cell, &trame, &allocate);
      player_view_treatement(ref, pos, ini, player);
      if (ini[2] < ref[2])
	strcat(trame, ",");
      ++ref[0];
    }
  trame = strcat(trame, "}\n");
  return (trame);
}
