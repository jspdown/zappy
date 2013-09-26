/*
** map_generate.c for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu Jun 20 15:32:37 2013 alexis leprovost
** Last update Sat Jul 13 13:01:31 2013 alexis leprovost
*/

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <strings.h>

#include "map.h"
#include "extend.h"
#include "ressource.h"
#include "core.h"

t_core	g_core;

void	map_generate_food(t_map* map, size_t food)
{
  int		x;
  int		y;

  while (food)
    {
      x = rand() % map->__width__;
      y = rand() % map->__height__;
      ++map->__cells__[y][x].ressources[FOOD];
      --food;
    }
}

static void	map_generate_ressource(t_map* map, int freq)
{
  int		x;
  int		y;
  int		r;

  y = -1;
  while ((size_t)++y < map->__height__)
    {
      x = -1;
      while ((size_t)++x < map->__width__)
	{
	  r = 0;
	  while (++r < MAX_RESSOURCE_TYPE)
	    if ((rand() % 100) <= freq)
	      ++map->__cells__[y][x].ressources[r];
	}
    }
}

t_bool	map_generate(t_map* map, double freq)
{
  size_t	food;

  if (!map || freq < MIN_FREQ || freq > MAX_FREQ || !map->__cells__)
    return (FALSE);
  food = (NB_FOOD * freq / 100);
  food *= ((t_team*)g_core.team->front(g_core.team))->size;
  food *= g_core.team->size(g_core.team);
  food += map->__width__ * map->__height__;
  map_generate_food(map, freq);
  map_generate_ressource(map, (int)freq);
  return (TRUE);
}

t_bool	map_create(t_map* map, size_t width, size_t height)
{
  size_t	y;
  size_t	x;

  if (!map || width > MAX_SIZE || width < MIN_SIZE ||
      height > MAX_SIZE || height < MIN_SIZE ||
      !(map->__cells__ = malloc(sizeof(t_cell*) * height)))
    return (FALSE);
  map->__width__ = width;
  map->__height__ = height;
  y = -1;
  while (++y < height)
    {
      x = -1;
      if (!(map->__cells__[y] = malloc(sizeof(t_cell) * width)))
	return (FALSE);
      while (++x < width)
	{
	  bzero(map->__cells__[y][x].ressources,
		sizeof(size_t) * MAX_RESSOURCE_TYPE);
	  map->__cells__[y][x].players = 0;
	}
    }
  return (TRUE);
}
