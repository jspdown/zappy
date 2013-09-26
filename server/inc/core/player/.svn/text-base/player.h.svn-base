/*
** player.h for player in /home/antiqe/Documents/zappy/server/inc/core
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri Jun 14 15:05:36 2013 ronan guiho
** Last update Tue Jul  9 13:34:26 2013 alexis leprovost
*/

#ifndef __PLAYER_H__
# define __PLAYER_H__

# include <time.h>

# include "network/client/client.h"
# include "network/aggregator/aggregator.h"
# include "list.h"
# include "ressource.h"
# include "team.h"

typedef struct s_view
{
  int x;
  int y;
  int dir;
  int axe;
} t_view;

typedef enum e_direction
  {
    NORTH = 1,
    EAST,
    SOUTH,
    WEST,
    MAX_DIRECTION
  } t_direction;

typedef enum e_player_type
  {
    BOT = 0,
    GRAPHIC,
    UNKNOWN
  } t_player_type;

typedef struct s_player t_player;
struct s_player
{
  t_client*	client;
  size_t	id;
  int		x;
  int		y;
  char		level;
  t_direction	direction;
  int		inventory[MAX_RESSOURCE_TYPE];
  t_team*	team;
  t_player_type	type;
  t_aggregator* aggr;
  time_t	ctime;
  t_list*	action;
  size_t	error;
};

typedef struct s_egg
{
  t_team*	team;
  int		x;
  int		y;
  size_t	id;
  t_player*	player;
} t_egg;

t_player *new_player();
void delete_player(t_player *player);

char *player_view(t_player *player);
void player_view_limit(int *pos);
void player_view_treatement(int *ref, int *pos, int *ini,
			    t_player *player);
void player_view_move(t_player *player, int *pos, int *ini,
		      int i);

#endif
