/*
** map_util.c for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue Jun 18 18:39:13 2013 alexis leprovost
** Last update Mon Jul  8 14:51:48 2013 ronan guiho
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

#include "map.h"
#include "extend.h"

t_cell*	map_at(t_map* map, size_t x, size_t y)
{
  if (!map || x >= map->__width__ || y >= map->__height__)
    return (NULL);
  return (&map->__cells__[y][x]);
}

t_bool	map_is_create(t_map* map)
{
  return (map && map->__cells__ ? TRUE : FALSE);
}

size_t	map_width(t_map* map)
{
  return (map ? map->__width__ : 0);
}

size_t	map_height(t_map* map)
{
  return (map ? map->__height__ : 0);
}

void	map_dump(t_map* map)
{
  size_t	x;
  size_t	y;

  if (map && map->__cells__)
    {
      y = -1;
      while (++y < map->__height__)
	{
	  x = -1;
	  while (++x < map->__width__)
	    printf("[%ld][%ld] %s:%ld %s:%ld %s:%ld %s:%ld %s:%ld %s:%ld %s:%ld\n",
		   x, y, g_ressource_string[0], map->__cells__[y][x].ressources[0],
		   g_ressource_string[1], map->__cells__[y][x].ressources[1],
		   g_ressource_string[2], map->__cells__[y][x].ressources[2],
		   g_ressource_string[3], map->__cells__[y][x].ressources[3],
		   g_ressource_string[4], map->__cells__[y][x].ressources[4],
		   g_ressource_string[5], map->__cells__[y][x].ressources[5],
		   g_ressource_string[6], map->__cells__[y][x].ressources[6]);
	}
    }
}
