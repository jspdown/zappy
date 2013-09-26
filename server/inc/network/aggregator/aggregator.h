/*
** aggregator.h for aggregator in /home/antiqe/Documents/zappy/server/src/network/agregator
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Jul  1 10:24:18 2013 ronan guiho
** Last update Sat Jul 13 12:37:49 2013 alexis leprovost
*/

#ifndef __AGGREGATOR_H__
#define __AGGREGATOR_H__

#include "list.h"
#include "network/message/message.h"

typedef struct s_aggregator t_aggregator;
struct s_aggregator
{
  t_list *queue;
  char *delim;
  unsigned int size_delim;
  void (*push)(t_aggregator *, t_message *msg);
};

t_aggregator *new_aggregator(char *delim);
void delete_aggregator(t_aggregator *aggr);

void aggregator_integrity(t_aggregator *aggr, void *data);
void aggregator_push(t_aggregator *aggr, t_message *msg);
void aggregator_integrity_buffer(char *buffer, t_message *msg);

#endif
