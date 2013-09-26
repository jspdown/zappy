/*
** list_algoritm.c for list in /home/leprov_a//libs/c/list
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Mar 29 15:57:13 2013 alexis leprovost
** Last update Sat Jul  6 15:31:08 2013 alexis leprovost
*/

#include <stdlib.h>

#include "list.h"

void*	list_find_if(t_list *list, void* data, t_func_cmp func)
{
  t_node*	tmp;
  t_node*	save;

  if (!list || !list->__head__ || !func)
    return (NULL);
  tmp = list->__head__;
  while (tmp)
    {
      save = tmp->next;
      if (func(tmp->data, data))
	return (tmp->data);
      tmp = save;
    }
  return (NULL);
}

int	list_remove_if(t_list* list, void* data,
		       t_func_cmp func1, t_func_clear func2)
{
  t_node*	tmp;
  size_t	n;
  size_t	c;

  c = 0;
  n = 0;
  if (!list || !list->__head__ || !func1)
    return (0);
  tmp = list->__head__;
  while (tmp)
    if (!func1(tmp->data, data))
      {
	tmp = tmp->next;
	func2 ? func2(list_pop_at(list, n)) : list_pop_at(list, n);
	++c;
      }
    else
      {
	++n;
	tmp = tmp->next;
      }
  return (c);
}

void	list_foreach(t_list* list, t_func_foreach func)
{
  t_node*	tmp;
  t_node*	save;

  tmp = !list || !list->__head__ ? NULL : list->__head__;
  while (tmp && func)
    {
      save = tmp->next;
      func(tmp->data);
      tmp = save;
    }
}

int	list_map(t_list* list, t_func_map func)
{
  t_node*	tmp;
  int		n;
  t_node*	save;

  n = 0;
  tmp = !list || !list->__head__ ? NULL : list->__head__;
  while (tmp && func)
    {
      save = tmp->next;
      n += func(tmp->data);
      tmp = save;
    }
  return (n);
}
