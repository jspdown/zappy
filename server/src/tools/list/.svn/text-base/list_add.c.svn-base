/*
** list_add.c for list in /home/leprov_a//libs/c/list
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Mar 29 15:57:13 2013 alexis leprovost
** Last update Tue Jul  2 11:39:22 2013 alexis leprovost
*/

#include <stdlib.h>

#include "list.h"

int	list_push_front(t_list* list, void* data)
{
  t_node*	new;

  if (!list || !(new = malloc(sizeof(t_node))))
    return (-1);
  new->next = list->__head__;
  new->prev = NULL;
  new->data = data;
  if (list->__head__)
    list->__head__->prev = new;
  else
    list->__tail__ = new;
  list->__head__ = new;
  ++list->__size__;
  return (0);
}

int	list_push_back(t_list* list, void* data)
{
  t_node*	new;

  if (!list || !list->__head__)
    return (list_push_front(list, data));
  if (!(new = malloc(sizeof(t_node))))
    return (-1);
  new->next = NULL;
  new->data = data;
  list->__tail__->next = new;
  new->prev = list->__tail__;
  ++list->__size__;
  list->__tail__ = new;
  return (0);
}

int	list_push_at(t_list* list, void* data, size_t n)
{
  t_node*	new;
  t_node*	tmp;

  if (!list || !list->__head__ || !n)
    return (list_push_front(list, data));
  if ((n + 1) >= list->__size__)
    return (list_push_back(list, data));
  if (!(new = malloc(sizeof(t_node))))
    return (-1);
  new->data = data;
  tmp = n < (list->__size__ / 2) ? list_head(list, n) : list_tail(list, n);
  if (!tmp)
    return (-1);
  new->next = tmp->next;
  if (new->next)
    new->next->prev = new;
  tmp->next = new;
  new->prev = tmp;
  ++list->__size__;
  return (0);
}
