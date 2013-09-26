/*
** uuid.h for uuid in /home/leprov_a//project/tek2/zappy/dev/server/inc/tools/uuid
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Jun 28 14:08:00 2013 alexis leprovost
** Last update Tue Jul  2 09:52:57 2013 alexis leprovost
*/

#ifndef _UUID_H_
# define _UUID_H_

# include <sys/types.h>

# include "list.h"
# include "extend.h"

typedef struct s_uuid
{
  size_t	__capacity__;
  t_list*	__pool__;
  size_t	(*get)(struct s_uuid*);
  t_bool	(*set)(struct s_uuid*, size_t);
  t_bool	(*extend)(struct s_uuid*, size_t);
  t_bool	(*create)(struct s_uuid*, size_t);
  t_bool	(*is_create)(struct s_uuid*);
  size_t	(*capacity)(struct s_uuid*);
  size_t	(*size)(struct s_uuid*);
} t_uuid;

t_uuid*	new_uuid();
void	delete_uuid(t_uuid** uuid);

size_t	uuid_get(t_uuid* uuid);
t_bool	uuid_set(t_uuid* uuid, size_t id);
t_bool	uuid_extend(t_uuid* uuid, size_t extend);
t_bool	uuid_create(t_uuid* uuid, size_t capacity);
t_bool	uuid_is_create(t_uuid* uuid);
size_t	uuid_capacity(t_uuid* uuid);
size_t	uuid_size(t_uuid* uuid);

#endif /* _UUID_H_ */
