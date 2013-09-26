/*
** protocol_do.c for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu Jul 11 12:02:15 2013 alexis leprovost
** Last update Thu Jul 11 23:08:25 2013 alexis leprovost
*/

#include <stdlib.h>
#include <string.h>

#include "protocol.h"
#include "extend.h"
#include "core.h"

t_core	g_core;

static void	protocol_short_position(t_core* core, t_player* player,
					int* x, int *y)
{
  int	res[6][3];
  int	i[2];

  i[0] = ((player->x < *x) ? -1 : 1 ) * (int)core->map->width(core->map);
  i[1] = ((player->y < *y) ? -1 : 1 ) * (int)core->map->height(core->map);
  res[1][0] = ABS(*x - player->x) + ABS(*y - player->y);
  res[1][1] = *x;
  res[1][2] = *y;
  res[2][1] = *x + i[0];
  res[2][0] = ABS(res[2][1] - player->x) + ABS(*y - player->y);
  res[2][2] = *y;
  res[3][2] = *y + i[1];
  res[3][0] = ABS(*x - player->x) + ABS(res[3][2] - player->y);
  res[3][1] = *x;
  res[4][1] = res[2][1];
  res[4][2] = res[3][2];
  res[4][0] = ABS(res[2][1] - player->x) + ABS(res[3][2] - player->y);
  i[0] = 0;
  i[1] = 1;
  while (++i[0] < 5)
    if (res[i[1]][0] > res[i[0]][0])
      i[1] = i[0];
  *x = res[i[1]][1];
  *y = res[i[1]][2];
}

static int	protocol_define_side(t_player* player, int dir, int x, int y)
{
  const int	side[MAX_DIRECTION][9] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 2, 3, 4, 5, 6, 7, 8},
    {0, 3, 4, 5, 6, 7, 8, 1, 2},
    {0, 5, 6, 7, 8, 1, 2, 3, 4},
    {0, 7, 8, 1, 2, 3, 4, 5, 6}
  };
  int v[3];

  v[0] = ABS(player->x + player->y);
  v[1] = ABS(x + y);
  if (x == player->x && y == player->y)
    return (0);
  else if (v[0] == v[1])
    return (side[dir][(y > player->y ? 8 : 4)]);
  else if (ABS(y - player->y) == ABS(x - player->x))
    return (side[dir][(y > player->y ? 2 : 6)]);
  else if (player->x > x && v[0] > v[1] && y >= x)
    return (side[dir][7]);
  else if (player->x < x && v[0] < v[1] && y <= x)
    return (side[dir][3]);
  else if (player->y > y)
    return (side[dir][5]);
  else
    return (side[dir][1]);
}

static void	protocol_define_pos(t_player* player, t_map* map, int dir)
{
  const char	move[MAX_DIRECTION][2] = {
    {0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1}
  };

  player->y += move[dir][0];
  if (player->y >= (int)map->height(map))
    player->y = 0;
  if (player->y < 0)
    player->y = map->height(map) - 1;
  player->x += move[dir][1];
  if (player->x >= (int)map->width(map))
    player->x = 0;
  if (player->x < 0)
    player->x = map->width(map) - 1;
}

void	protocol_do_broadcast(void* d1, void* d2)
{
  t_broadcast*	b;
  t_player*	p;
  int		x;
  int		y;
  t_action	action;

  if ((p = (t_player*)d1) && (b = (t_broadcast*)d2) && p->type == BOT &&
      b->player != p)
    {
      x = p->x;
      y = p->y;
      protocol_short_position(&g_core, b->player, &x, &y);
      b->message[8] = protocol_define_side(b->player, p->direction, x, y) + 48;
      action.index = p->client->sock[TCP];
      action.ctime = p->ctime;
      protocol_send(&g_core, &action, b->message);
    }
}

void	protocol_do_expulse(void* d1, void* d2)
{
  t_broadcast*	b;
  t_player*	p;
  t_action	action;
  int		k;

  if ((p = (t_player*)d1) && (b = (t_broadcast*)d2) && p->type == BOT &&
      b->player != p && p->x == b->player->x && p->y == b->player->y)
    {
      protocol_define_pos(p, g_core.map, b->player->direction);
      k = protocol_define_side(b->player, p->direction, p->x, p->y);
      b->message[13] = k + 48;
      action.index = p->client->sock[TCP];
      action.ctime = p->ctime;
      g_core.graphic->foreach2(g_core.graphic, protocol_pos_player_notify,
			       (void*)p);
      protocol_send(&g_core, &action, b->message);
    }
}
