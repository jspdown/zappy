/*
** core_table.c for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu Jul 11 15:22:34 2013 alexis leprovost
** Last update Fri Jul 12 18:16:50 2013 alexis leprovost
*/

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <sys/time.h>
#include <unistd.h>

#include "core.h"
#include "extend.h"
#include "action.h"
#include "list.h"

double	g_ref_action[MAX_ACTION_TYPE][2];

static void	core_init_table_part2()
{
  g_ref_action[DEATH][1] = TAIL;
  g_ref_action[ECLOSION][1] = TAIL;
  g_ref_action[SYNC][1] = HEAD;
  g_ref_action[DISCONNECT][1] = HEAD;
  g_ref_action[ELEVATION][1] = TAIL;
  g_ref_action[CORRUPT][1] = HEAD;
  g_ref_action[WIN][1] = HEAD;
  g_ref_action[FORK][1] = TAIL;
  g_ref_action[DATA_MAP_CHUNK][1] = HEAD;
}

void	core_init_table_part()
{
  g_ref_action[MOVE][1] = TAIL;
  g_ref_action[RIGHT][1] = TAIL;
  g_ref_action[LEFT][1] = TAIL;
  g_ref_action[SEE][1] = TAIL;
  g_ref_action[INVENTORY][1] = HEAD;
  g_ref_action[TAKE][1] = TAIL;
  g_ref_action[DROP][1] = TAIL;
  g_ref_action[EXPULSE][1] = TAIL;
  g_ref_action[BROADCAST][1] = TAIL;
  g_ref_action[INCANTATION][1] = HEAD;
  g_ref_action[PRE_FORK][1] = HEAD;
  g_ref_action[CONNECT_NBR][1] = HEAD;
  g_ref_action[SIZE_MAP][1] = HEAD;
  g_ref_action[DATA_CASE][1] = HEAD;
  g_ref_action[DATA_MAP][1] = HEAD;
  g_ref_action[GET_TEAM][1] = HEAD;
  g_ref_action[POS_PLAYER][1] = HEAD;
  g_ref_action[LEVEL_PLAYER][1] = HEAD;
  g_ref_action[DATA_PLAYER][1] = HEAD;
  g_ref_action[GET_TIME][1] = HEAD;
  g_ref_action[SET_TIME][1] = HEAD;
  core_init_table_part2();
}

static t_bool	core_init_table_time2(double time)
{
  g_ref_action[DEATH][0] = 125.99f / time;
  g_ref_action[ECLOSION][0] = 599.99f / time;
  g_ref_action[SYNC][0] = 0.0f;
  g_ref_action[DISCONNECT][0] = 0.0f;
  g_ref_action[ELEVATION][0] = 299.99f / time;
  g_ref_action[CORRUPT][0] = 1259.99f / time;
  g_ref_action[WIN][0] = 0.0f;
  g_ref_action[FORK][0] = 41.99f / time;
  g_ref_action[DATA_MAP_CHUNK][0] = 0.0f;
  return (TRUE);
}

t_bool	core_init_table_time(double time)
{
  if (time < 0.0f)
    return (FALSE);
  g_ref_action[MOVE][0] = 6.99f / time;
  g_ref_action[RIGHT][0] = 6.99f / time;
  g_ref_action[LEFT][0] = 6.99f / time;
  g_ref_action[SEE][0] = 6.99f / time;
  g_ref_action[INVENTORY][0] = 0.99f / time;
  g_ref_action[TAKE][0] = 6.99f / time;
  g_ref_action[DROP][0] = 6.99f / time;
  g_ref_action[EXPULSE][0] = 6.99f / time;
  g_ref_action[BROADCAST][0] = 6.99f / time;
  g_ref_action[INCANTATION][0] = 0.0f;
  g_ref_action[PRE_FORK][0] = 0.0f;
  g_ref_action[CONNECT_NBR][0] = 0.0f;
  g_ref_action[SIZE_MAP][0] = 0.0f;
  g_ref_action[DATA_CASE][0] = 0.0f;
  g_ref_action[DATA_MAP][0] = 0.0f;
  g_ref_action[GET_TEAM][0] = 0.0f;
  g_ref_action[POS_PLAYER][0] = 0.0f;
  g_ref_action[LEVEL_PLAYER][0] = 0.0f;
  g_ref_action[DATA_PLAYER][0] = 0.0f;
  g_ref_action[GET_TIME][0] = 0.0f;
  g_ref_action[SET_TIME][0] = 0.0f;
  return (core_init_table_time2(time));
}
