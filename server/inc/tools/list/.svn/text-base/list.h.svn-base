/*
** list.h for list in /home/leprov_a//project/tek2/zappy/dev/server/inc/tools/uuid
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Jun 28 14:08:13 2013 alexis leprovost
** Last update Fri Jul 12 15:02:35 2013 alexis leprovost
*/

#ifndef __LIST_H__
# define __LIST_H__

# include <sys/types.h>

# include "node.h"

typedef enum s_list_type
  {
    HEAD = 0,
    TAIL
  } t_list_type;

typedef int	(*t_func_cmp)(void*, void*);
typedef void	(*t_func_foreach)(void*);
typedef void	(*t_func_foreach2)(void*, void*);
typedef int	(*t_func_map)(void*);
typedef int	(*t_func_map2)(void*, void*);
typedef void	(*t_func_clear)(void*);
typedef int	(*t_func_insert)(void*, void*);

typedef struct s_list
{
  t_node*	__head__;
  t_node*	__tail__;
  size_t	__size__;
  int		(*push_front)(struct s_list*, void*);
  int		(*push_back)(struct s_list*, void*);
  int		(*push_at)(struct s_list*, void*, size_t);
  void*		(*pop_front)(struct s_list*);
  void*		(*pop_back)(struct s_list*);
  void*		(*pop_at)(struct s_list*, size_t);
  void		(*clear)(struct s_list*, t_func_clear);
  void		(*reverse)(struct s_list*);
  void		(*sort)(struct s_list*, t_func_cmp);
  void		(*rsort)(struct s_list*, t_func_cmp);
  void*		(*front)(struct s_list*);
  void*		(*back)(struct s_list*);
  void*		(*at)(struct s_list*, size_t);
  size_t	(*size)(struct s_list*);
  int		(*empty)(struct s_list*);
  void*		(*find_if)(struct s_list*, void*, t_func_cmp);
  int		(*remove_if)(struct s_list*, void*, t_func_cmp, t_func_clear);
  void		(*foreach)(struct s_list*, t_func_foreach);
  int		(*map)(struct s_list*, t_func_map);
  void		(*foreach2)(struct s_list*, t_func_foreach2, void*);
  int		(*map2)(struct s_list*, t_func_map2, void*);
  int		(*erase)(struct s_list*, void*, t_func_clear);
  int		(*insert)(struct s_list*, void*, t_func_insert, t_list_type);
  int		(*uniq)(struct s_list*, t_func_cmp, t_func_clear);
} t_list;

t_list*	new_list();
void	delete_list(t_list** list, t_func_clear func);

int	list_push_front(t_list* list, void* data);
int	list_push_back(t_list* list, void* data);
int	list_push_at(t_list* list, void* data, size_t n);

void*	list_pop_front(t_list* list);
void*	list_pop_back(t_list* list);
void*	list_pop_at(t_list* list, size_t n);

void	list_clear(t_list* list, t_func_clear func);
void	list_reverse(t_list* list);
void	list_sort(t_list* list, t_func_cmp func);
void	list_rsort(t_list* list, t_func_cmp func);
int	list_uniq(t_list* list, t_func_cmp cmp, t_func_clear clear);

void*	list_front(t_list* list);
void*	list_back(t_list* list);
void*	list_at(t_list* list, size_t n);
size_t	list_size(t_list* list);
int	list_empty(t_list* list);

void*	list_find_if(t_list* list, void* data, t_func_cmp func);
int	list_remove_if(t_list* list, void* data, t_func_cmp func1,
		       t_func_clear func2);
void	list_foreach(t_list* list, t_func_foreach func);
int	list_map(t_list* list, t_func_map func);

void	list_foreach2(t_list* list, t_func_foreach2 func, void* data);
int	list_map2(t_list* list, t_func_map2 func, void* data);
int	list_erase(t_list* list, void* data, t_func_clear func);
int	list_insert(t_list* list, void* data, t_func_insert func,
		    t_list_type type);

t_node*	list_head(t_list* list, size_t n);
t_node*	list_tail(t_list* list, size_t n);
t_node*	list_find_from_head(t_list* list, void* data, t_func_insert func);
t_node*	list_find_from_tail(t_list* list, void* data, t_func_insert func);

#endif
