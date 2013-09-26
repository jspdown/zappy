/*
** list_insert.c for list in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu Jul  4 18:25:18 2013 alexis leprovost
** Last update Sat Jul  6 15:30:54 2013 alexis leprovost
*/

#include <stdlib.h>

#include "list.h"

static int	list_insert_head(t_list* list, void* data, t_func_insert func)
{
  t_node*	tmp;
  t_node*	new;

  tmp = list->__head__;
  while (tmp && !func(tmp->data, data))
    tmp = tmp->next;
  if (!tmp)
    return (list_push_back(list, data));
  if (tmp == list->__head__)
    return (list_push_front(list, data));
  if (!(new = malloc(sizeof(t_node))))
    return (-1);
  new->data = data;
  new->prev = tmp->prev;
  if (tmp->prev)
    tmp->prev->next = new;
  new->next = tmp;
  tmp->prev = new;
  ++list->__size__;
  return (0);
}

static int	list_insert_tail(t_list* list, void* data, t_func_insert func)
{
  t_node*	tmp;
  t_node*	new;

  tmp = list->__tail__;
  while (tmp && !func(tmp->data, data))
    tmp = tmp->prev;
  if (!tmp)
    return (list_push_front(list, data));
  if (tmp == list->__tail__)
    return (list_push_back(list, data));
  if (!(new = malloc(sizeof(t_node))))
    return (-1);
  new->data = data;
  new->prev = tmp;
  new->next = tmp->next;
  if (tmp->next)
    tmp->next->prev = new;
  tmp->next = new;
  ++list->__size__;
  return (0);
}

typedef int	(*t_insert_func)(t_list*, void*, t_func_insert);

int	list_insert(t_list* list, void* data,
		    t_func_insert func, t_list_type type)
{
  const t_insert_func	insert[2] = {
    &list_insert_head,
    &list_insert_tail
  };

  if (!list || !func)
    return (-1);
  return (insert[type](list, data, func));
}
