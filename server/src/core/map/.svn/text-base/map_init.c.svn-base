/*
** map_init.c for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue Jun 18 18:14:24 2013 alexis leprovost
** Last update Mon Jul  1 22:03:36 2013 alexis leprovost
*/

#include <stdlib.h>

#include "map.h"
#include "list.h"
#include "extend.h"

static void  	map_init_attr(t_map* map)
{
  map->__cells__ = NULL;
  map->__width__ = 0;
  map->__height__ = 0;
}

static void	map_init_method(t_map* map)
{
  map->at = &map_at;
  map->create = &map_create;
  map->generate = &map_generate;
  map->is_create = &map_is_create;
  map->width = &map_width;
  map->height = &map_height;
  map->dump = &map_dump;
}

t_map*	new_map()
{
  t_map*	new;

  if (!(new = malloc(sizeof(t_map))))
    return (NULL);
  map_init_attr(new);
  map_init_method(new);
  return (new);
}

void	delete_map(t_map** map)
{
  size_t	y;

  if (*map)
    {
      if ((*map)->__cells__)
	{
	  y = -1;
	  while (++y < (*map)->__height__)
	    {
	      free((*map)->__cells__[y]);
	      (*map)->__cells__[y] = NULL;
	    }
	  free((*map)->__cells__);
	}
      free(*map);
      *map = NULL;
    }
}
