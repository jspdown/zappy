/*
** list_access.c for list in /home/leprov_a//libs/c/list
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Mar 29 15:57:13 2013 alexis leprovost
** Last update Tue Jul  2 11:22:35 2013 alexis leprovost
*/

#include <stdlib.h>

#include "list.h"

void*	list_front(t_list* list)
{
  return (!list || !list->__head__ ? NULL : list->__head__->data);
}

void*	list_back(t_list* list)
{
  return (!list || !list->__tail__ ? NULL : list->__tail__->data);
}

void*	list_at(t_list* list, size_t n)
{
  t_node*	tmp;

  if (!list || !list->__head__)
    return (NULL);
  if (!n)
    return (list_front(list));
  if ((n + 1) >= list->__size__)
    return (list_back(list));
  tmp = n < (list->__size__ / 2) ? list_head(list, n) : list_tail(list, n);
  return (tmp ? tmp->data : NULL);
}

size_t	list_size(t_list* list)
{
  return (!list ? 0 : list->__size__);
}

int	list_empty(t_list* list)
{
  return (!list || !list->__head__ ? 1 : 0);
}
