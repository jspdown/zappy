/*
** aggregator.h for aggregator in /home/guiho_r/depot/zappy/server/inc/tools/aggregator
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Jun  2 13:56:54 2013 ronan guiho
** Last update Sun Jun  2 14:17:31 2013 ronan guiho
*/

#ifndef __AGGREGATOR_H__
#define __AGGREGATOR_H__

#include <list.h>

typedef struct s_aggregator t_aggregator
struct s_aggregator
{
  t_list *queue;
  void (*push)(t_aggregator *, char *);
};

#endif
