/*
** cell.h for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue Jun 18 17:43:17 2013 alexis leprovost
** Last update Mon Jul  1 16:07:21 2013 alexis leprovost
*/

#ifndef _CELL_H_
# define _CELL_H_

# include "list.h"
# include "ressource.h"

typedef struct s_cell
{
  size_t	ressources[MAX_RESSOURCE_TYPE];
  size_t	players;
} t_cell;

#endif /* _CASE_H_ */
