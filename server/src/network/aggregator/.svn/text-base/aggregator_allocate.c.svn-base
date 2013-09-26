/*
** aggregator_allocate.c for aggregator_allocate in /home/antiqe/Documents/zappy/server/src/network/agregator
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Jul  1 10:22:19 2013 ronan guiho
** Last update Wed Jul 10 12:39:54 2013 ronan guiho
*/

#include <stdlib.h>
#include <string.h>

#include "network/aggregator/aggregator.h"

void aggregator_assign(t_aggregator *aggr)
{
  aggr->push = &aggregator_push;
}

t_aggregator *new_aggregator(char *delim)
{
  t_aggregator *aggr;

  if ((aggr = malloc(sizeof(t_aggregator))) == NULL)
    return (NULL);
  if ((aggr->queue = new_list()) == NULL)
    return (NULL);
  aggr->delim = delim;
  aggr->size_delim = strlen(aggr->delim);
  aggregator_assign(aggr);
  return (aggr);
}

void delete_aggregator(t_aggregator *aggr)
{
  if (aggr)
    {
      if (aggr->delim)
	free(aggr->delim);
      if (aggr->queue)
	delete_list(&aggr->queue, NULL);
      free(aggr);
    }
}
