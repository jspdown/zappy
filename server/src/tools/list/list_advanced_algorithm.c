/*
** list_advanced_algoritm.c for list in /home/leprov_a//libs/c/list
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Mar 29 15:57:13 2013 alexis leprovost
** Last update Thu Jul 11 22:09:10 2013 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void	list_foreach2(t_list* list, t_func_foreach2 func, void *data)
{
  t_node*	tmp;
  t_node*	save;

  tmp = !list || !list->__head__ ? NULL : list->__head__;
  while (tmp && func)
    {
      save = tmp->next;
      func(tmp->data, data);
      tmp = save;
    }
}

int	list_map2(t_list* list, t_func_map2 func, void* data)
{
  t_node*	tmp;
  int		n;
  t_node*	save;

  n = 0;
  tmp = !list || !list->__head__ ? NULL : list->__head__;
  while (tmp && func)
    {
      save = tmp->next;
      n += func(tmp->data, data);
      tmp = save;
    }
  return (n);
}

int	list_erase(t_list* list, void* data, t_func_clear func)
{
  t_node*	tmp;

  tmp = !list || !list->__head__ ? NULL : list->__head__;
  while (tmp)
    {
      if (tmp->data == data)
	{
	  if (tmp == list->__head__)
	    func ? func(list_pop_front(list)) : list_pop_front(list);
	  else if (tmp == list->__tail__)
	    func ? func(list_pop_back(list)) : list_pop_back(list);
	  else
	    {
	      tmp->prev->next = tmp->next;
	      tmp->next->prev = tmp->prev;
	      if (func)
		func(tmp->data);
	      free(tmp);
	      --list->__size__;
	    }
	  return (1);
	}
      tmp = tmp->next;
    }
  return (0);
}
