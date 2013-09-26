/*
** stack_init.c for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue Jul  2 11:58:02 2013 alexis leprovost
** Last update Mon Jul  8 09:23:43 2013 alexis leprovost
*/

#include <stdlib.h>

#include "stack.h"
#include "list.h"
#include "timer.h"

static void	stack_init_attr(t_stack* stack)
{
  stack->__actions__ = new_list();
}

static void	stack_init_method(t_stack* stack)
{
  stack->set = &stack_set;
  stack->get = &stack_get;
  stack->ready = &stack_ready;
  stack->time = &stack_time;
}

static void	stack_free(void* data)
{
  t_action*	action;

  action = (t_action*)data;
  if (action)
    {
      delete_timer(&action->timer);
      if (action->data)
	free(action->data);
      free(action);
    }
}

t_stack*	new_stack()
{
  t_stack*	new;

  if (!(new = malloc(sizeof(t_stack))))
    return (NULL);
  stack_init_attr(new);
  stack_init_method(new);
  if (!new->__actions__)
    {
      free(new);
      return (NULL);
    }
  return (new);
}

void		delete_stack(t_stack** stack)
{
  if (stack)
    {
      delete_list(&(*stack)->__actions__, &stack_free);
      free(*stack);
      stack = NULL;
    }
}
