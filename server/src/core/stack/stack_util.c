/*
** stack_util.c for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue Jul  2 12:05:10 2013 alexis leprovost
** Last update Fri Jul 12 18:09:57 2013 alexis leprovost
*/

#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "list.h"
#include "extend.h"
#include "action.h"

double	g_ref_action[MAX_ACTION_TYPE][2];

static int	stack_insert(void* d1, void* d2, t_list_type type)
{
  t_action*	a1;
  t_action*	a2;
  double	t1;
  double	t2;

  a1 = (t_action*)d1;
  a2 = (t_action*)d2;
  if (!a1 || !a2)
    return (0);
  t1 = g_ref_action[a1->type][0] - a1->timer->get_time(a1->timer);
  t2 = g_ref_action[a2->type][0] - a2->timer->get_time(a2->timer);
  return (type == HEAD ? t1 >= t2 : t1 <= t2);
}

static int	stack_insert_from_head(void* d1, void* d2)
{
  return (stack_insert(d1, d2, HEAD));
}

static int	stack_insert_from_tail(void* d1, void* d2)
{
  return (stack_insert(d1, d2, TAIL));
}

t_bool		stack_set(t_stack* stack, t_action* action)
{
  if (!stack || !action)
    return (FALSE);
  action->timer->start(action->timer);
  action->timer->stop(action->timer);
  if (g_ref_action[action->type][1] == HEAD)
    stack->__actions__->insert(stack->__actions__, (void*)action,
			       &stack_insert_from_head, HEAD);
  else
    stack->__actions__->insert(stack->__actions__, (void*)action,
			       &stack_insert_from_tail, TAIL);
  action->timer->start(action->timer);
  return (TRUE);
}

t_action*	stack_get(t_stack* stack)
{
  if (!stack)
    return (NULL);
  return (stack->__actions__->pop_front(stack->__actions__));
}
