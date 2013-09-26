/*
** list_util.c for list in /home/leprov_a//libs/c/list
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Mar 29 15:57:13 2013 alexis leprovost
** Last update Sat Jul 13 11:21:11 2013 alexis leprovost
*/

#include <stdlib.h>

#include "list.h"

void	list_clear(t_list* list, t_func_clear func)
{
  void	*data;

  while (!list->empty(list))
    {
      data = list->pop_front(list);
      if (func)
	func(data);
    }
}

void	list_reverse(t_list* list)
{
  t_node*	next;
  t_node*	tmp;

  tmp = !list || !list->__head__ ? NULL : list->__head__;
  while (tmp)
    {
      next = tmp->next;
      tmp->next = tmp->prev;
      tmp->prev = next;
      if (!next)
	list->__head__ = tmp;
      tmp = next;
    }
}

void	list_sort(t_list* list, t_func_cmp func)
{
  t_node*	tmp;
  t_node*	cur;

  tmp = !list || !list->__head__ ? NULL : list->__head__;
  while (tmp && func)
    if (tmp->next && func(tmp->data, tmp->next->data) > 0)
      {
	cur = tmp->next;
	cur->prev = tmp->prev;
	if (cur->prev)
	  cur->prev->next = cur;
	else
	  list->__head__ = cur;
	if (cur->next)
	  cur->next->prev = tmp;
	tmp->next = cur->next;
	cur->next = tmp;
	tmp->prev = cur;
	tmp = list->__head__;
      }
    else
      tmp = tmp->next;
}

void	list_rsort(t_list* list, t_func_cmp func)
{
  if (list)
    {
      list->sort(list, func);
      list->reverse(list);
    }
}

int	list_uniq(t_list* list, t_func_cmp cmp, t_func_clear clear)
{
  t_node*	cur;
  t_node*	tmp;
  size_t	size;

  if (!list || !list->__head__ || !cmp)
    return (0);
  cur = list->__head__;
  size = list->__size__;
  while (cur)
    {
      tmp = list->__head__;
      while (tmp)
	if (tmp != cur && cmp(tmp->data, cur->data))
	  {
	    list_erase(list, tmp->data, clear);
	    tmp = NULL;
	  }
	else
	  tmp = tmp->next;
      cur = cur->next;
    }
  return (size == list->__size__);
}
