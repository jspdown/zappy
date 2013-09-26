/*
** list_tool.c for list in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue Jul  2 11:17:07 2013 alexis leprovost
** Last update Fri Jul  5 11:33:56 2013 alexis leprovost
*/

#include <stdlib.h>

#include "list.h"
#include "node.h"

t_node*	list_head(t_list* list, size_t n)
{
  t_node*	tmp;

  if (!list || !list->__head__)
    return (NULL);
  tmp = list->__head__;
  while (tmp->next && n)
    {
      tmp = tmp->next;
      --n;
    }
  return (tmp);
}

t_node*	list_tail(t_list* list, size_t n)
{
  t_node*	tmp;

  if (!list || !list->__head__)
    return (NULL);
  n = list->__size__ - n;
  tmp = list->__tail__;
  while (tmp->prev && n)
    {
      tmp = tmp->prev;
      --n;
    }
  return (tmp);
}
