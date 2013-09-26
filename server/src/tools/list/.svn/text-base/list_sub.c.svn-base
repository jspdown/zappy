/*
** list_sub.c for list in /home/leprov_a//libs/c/list
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Mar 29 15:57:13 2013 alexis leprovost
** Last update Thu Jul 11 15:21:08 2013 alexis leprovost
*/

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void*	list_pop_front(t_list* list)
{
  void*		data;
  t_node*	tmp;

  if (!list || !list->__head__)
    return (NULL);
  tmp = list->__head__->next;
  data = list->__head__->data;
  free(list->__head__);
  list->__head__ = tmp;
  if (list->__head__)
    list->__head__->prev = NULL;
  else
    list->__tail__ = NULL;
  --list->__size__;
  if (list->__size__ == 1)
    list->__tail__ = list->__head__;
  return (data);
}

void*	list_pop_back(t_list* list)
{
  void*		data;
  t_node*	tmp;

  if (!list || !list->__head__)
    return (NULL);
  if (list->__size__ == 1)
    return (list_pop_front(list));
  tmp = list->__tail__->prev;
  tmp->next = NULL;
  data = list->__tail__->data;
  free(list->__tail__);
  list->__tail__ = tmp;
  --list->__size__;
  return (data);
}

void*	list_pop_at(t_list* list, size_t n)
{
  void*		data;
  t_node*	tmp;

  if (!list || !list->__head__)
    return (NULL);
  if (!list->__head__->next || !n)
    return (list_pop_front(list));
  if (n >= list->__size__)
    return (list_pop_back(list));
  tmp = (n <= (list->__size__ / 2)) ? list_head(list, n) : list_tail(list, n);
  if (!tmp)
    return (NULL);
  data = tmp->data;
  tmp->prev->next = tmp->next;
  tmp->next->prev = tmp->prev;
  free(tmp);
  --list->__size__;
  return (data);
}
