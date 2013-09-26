/*
** player_view_aux.c for player_view_aux in /home/antiqe/Documents/zappy/server/src/core/map
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Jul  8 11:00:55 2013 ronan guiho
** Last update Sat Jul 13 12:35:55 2013 alexis leprovost
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

const t_view ref_view_move[] = {
  {0, 0, 0, 0},
  {-1, -1, 1, 0},
  {1, -1, 1, 1},
  {1, 1, -1, 0},
  {-1, 1, -1, 1}
};

void player_view_treatement(int *ref, int *pos, int *ini,
			    t_player *player)
{
  if (ref[0] == ref[1])
    {
      ref[0] = 0;
      ref[1] += 2;
      player_view_move(player, pos, ini, ini[2]);
    }
  else if (ini[2] == 0)
    player_view_move(player, pos, ini, ini[2]);
  else
    {
      pos[ref_view_move[player->direction].axe] += \
	ref_view_move[player->direction].dir;
      player_view_limit(pos);
    }
}

void player_view_limit(int *pos)
{
  if (pos[0] < 0)
    pos[0] = (g_core.map->__width__) + pos[0];
  else if (pos[0] >= (int)g_core.map->__width__)
    pos[0] = pos[0] - g_core.map->__width__;
  if (pos[1] < 0)
    pos[1] = (g_core.map->__height__) + pos[1];
  else if (pos[1] >= (int)g_core.map->__height__)
    pos[1] = pos[1] - g_core.map->__height__;
}
