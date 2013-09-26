/*
** map.h for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue Jun 18 11:42:30 2013 alexis leprovost
** Last update Sat Jul 13 13:01:58 2013 alexis leprovost
*/

#ifndef _MAP_H_
# define _MAP_H_

# include <sys/types.h>

# include "cell.h"
# include "extend.h"

# define MIN_SIZE	1
# define MAX_SIZE	1000000
# define MIN_FREQ	0.0
# define MAX_FREQ	100.0
# define NB_FOOD	500

typedef struct s_map
{
  t_cell**	__cells__;
  size_t	__width__;
  size_t	__height__;
  t_cell*	(*at)(struct s_map*, size_t, size_t);
  t_bool	(*create)(struct s_map*, size_t width, size_t height);
  t_bool	(*generate)(struct s_map*, double freq);
  t_bool	(*is_create)(struct s_map*);
  size_t	(*width)(struct s_map*);
  size_t	(*height)(struct s_map*);
  void		(*dump)(struct s_map*);
} t_map;

t_map*	new_map();
void	delete_map(t_map** map);

t_bool	map_create(t_map* map, size_t width, size_t height);
t_bool	map_generate(t_map* map, double freq);
t_cell*	map_at(t_map* map, size_t x, size_t y);
t_bool	map_is_create(t_map* map);
size_t	map_width(t_map* map);
size_t	map_height(t_map* map);
void	map_dump(t_map* map);
void	map_generate_food(t_map* map, size_t food);

#endif /* _MAP_H_ */
