/*
** stack_tool.c for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue Jul  2 12:23:43 2013 alexis leprovost
** Last update Fri Jul 12 17:57:47 2013 alexis leprovost
*/

#include <stdlib.h>
#include <stdio.h>

#include "stack.h"
#include "extend.h"
#include "action.h"

double	g_ref_action[MAX_ACTION_TYPE][2];

t_bool	stack_ready(t_stack* stack)
{
  t_action*	action;

  if (!stack)
    return (FALSE);
  action = stack->__actions__->front(stack->__actions__);
  if (!action)
    return (FALSE);
  return (action->timer->is_time_out(action->timer,
				     g_ref_action[action->type][0]));
}

double	stack_time(t_stack* stack)
{
  double	time;
  t_action*	action;

  if (!stack)
    return (-1.0f);
  action = (t_action*)stack->__actions__->front(stack->__actions__);
  if (!action)
    return (-1.0f);
  time = g_ref_action[action->type][0] -	\
    action->timer->get_time(action->timer);
  return (time < 0.0f ? 0.0f : time);
}
