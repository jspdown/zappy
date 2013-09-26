/*
** stack.h for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Jul  1 19:59:14 2013 alexis leprovost
** Last update Mon Jul  8 09:24:00 2013 alexis leprovost
*/

#ifndef _STACK_H_
# define _STACK_H_

# include "action.h"
# include "list.h"
# include "extend.h"

typedef struct s_stack
{
  t_list*	__actions__;
  t_bool	(*set)(struct s_stack*, t_action*);
  t_action*	(*get)(struct s_stack*);
  t_bool	(*ready)(struct s_stack*);
  double	(*time)(struct s_stack*);
} t_stack;

t_stack*	new_stack();
void		delete_stack(t_stack** stack);

t_bool		stack_set(t_stack* stack, t_action* action);
t_action*	stack_get(t_stack* stack);
t_bool		stack_ready(t_stack* stack);
double		stack_time(t_stack* stack);

#endif /* _STACK_H_ */
