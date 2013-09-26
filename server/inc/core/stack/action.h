/*
** action.h for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue Jul  2 10:40:10 2013 alexis leprovost
** Last update Thu Jul 11 21:48:53 2013 alexis leprovost
*/

#ifndef _ACTION_H_
# define _ACTION_H_

# include <time.h>

# include "timer.h"
# include "player.h"

typedef enum s_action_type
  {
    MOVE = 0,
    RIGHT,
    LEFT,
    SEE,
    INVENTORY,
    TAKE,
    DROP,
    EXPULSE,
    BROADCAST,
    INCANTATION,
    PRE_FORK,
    CONNECT_NBR,
    SIZE_MAP,
    DATA_CASE,
    DATA_MAP,
    GET_TEAM,
    POS_PLAYER,
    LEVEL_PLAYER,
    DATA_PLAYER,
    GET_TIME,
    SET_TIME,
    DEATH,
    ECLOSION,
    SYNC,
    DISCONNECT,
    ELEVATION,
    CORRUPT,
    WIN,
    FORK,
    DATA_MAP_CHUNK,
    MAX_ACTION_TYPE
  } t_action_type;

typedef struct s_action
{
  t_action_type	type;
  int		index;
  t_timer*	timer;
  void*		data;
  time_t	ctime;
} t_action;

typedef struct s_core	t_core;
typedef t_bool		(*t_action_func)(t_core*, t_player*, t_action*);

extern double	g_ref_action[MAX_ACTION_TYPE][2];

#endif /* _ACTION_H_ */
