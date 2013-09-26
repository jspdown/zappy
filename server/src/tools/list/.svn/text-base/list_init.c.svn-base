/*
** list_init.c for list in /home/leprov_a//libs/c/list
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Mar 29 15:57:13 2013 alexis leprovost
** Last update Thu Jul  4 15:38:53 2013 alexis leprovost
*/

#include <stdlib.h>

#include "list.h"

static void	list_init_method(t_list* list)
{
  list->push_front = &list_push_front;
  list->push_back = &list_push_back;
  list->push_at = &list_push_at;
  list->pop_front = &list_pop_front;
  list->pop_back = &list_pop_back;
  list->pop_at = &list_pop_at;
  list->clear = &list_clear;
  list->reverse = &list_reverse;
  list->sort = &list_sort;
  list->rsort = &list_rsort;
  list->front = &list_front;
  list->back = &list_back;
  list->at = &list_at;
  list->size = &list_size;
  list->empty = &list_empty;
  list->find_if = &list_find_if;
  list->remove_if = &list_remove_if;
  list->foreach = &list_foreach;
  list->map = &list_map;
  list->foreach2 = &list_foreach2;
  list->map2 = &list_map2;
  list->erase = &list_erase;
  list->insert = &list_insert;
  list->uniq = &list_uniq;
}

static void	list_init_attr(t_list* list)
{
  list->__head__ = NULL;
  list->__tail__ = NULL;
  list->__size__ = 0;
}

t_list*	new_list()
{
  t_list*	new;

  if ((new = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  list_init_attr(new);
  list_init_method(new);
  return (new);
}

void	delete_list(t_list** list, t_func_clear func)
{
  if (*list)
    {
      (*list)->clear(*list, func);
      free(*list);
      *list = NULL;
    }
}
