/*
** team.h for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Jul  1 14:19:41 2013 alexis leprovost
** Last update Fri Jul  5 01:56:18 2013 alexis leprovost
*/

#ifndef _TEAM_H_
# define _TEAM_H_

# include <sys/types.h>

typedef struct s_team
{
  char*		name;
  size_t	size;
  size_t	max;
} t_team;

#endif /* _TEAM_H_ */
