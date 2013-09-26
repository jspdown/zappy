/*
** aggregator_behaviour.c for aggregator_behaviour in /home/antiqe/Documents/zappy/server/src/network/aggregator
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Jul  1 10:31:58 2013 ronan guiho
** Last update Fri Jul 12 17:31:26 2013 ronan guiho
*/

#include <string.h>
#include <stdlib.h>

#include "network/message/message.h"
#include "network/aggregator/aggregator.h"

void aggregator_push(t_aggregator *aggr, t_message *msg)
{
  aggr->queue->push_back(aggr->queue, msg);
  aggregator_integrity(aggr, msg);
}
