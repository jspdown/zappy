/*
** aggregator_integrity.c for aggregator_integrity in /home/antiqe/Documents/zappy/server/src/network/aggregator
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Jul  1 13:34:50 2013 ronan guiho
** Last update Sat Jul 13 12:37:38 2013 alexis leprovost
*/

#include <string.h>
#include <stdlib.h>

#include "core/core.h"
#include "network/message/message.h"
#include "network/aggregator/aggregator.h"

t_core g_core;

void aggregator_integrity_sum(t_aggregator *aggr, t_message *msg)
{
  char b;
  int size;
  char *buffer;
  t_message *pop_msg;

  buffer = NULL;
  size = msg->size;
  while ((pop_msg = aggr->queue->pop_front(aggr->queue)) && pop_msg != msg)
    {
      b = (!buffer) ? 1 : 0;
      if ((buffer = realloc(buffer, sizeof(char) *
			    (size + pop_msg->size + 2))) != NULL)
	{
	  (b == 1) ? bzero(buffer, size + pop_msg->size + 2) :
	    bzero(&buffer[size], pop_msg->size + 2);
	  strcat(buffer, pop_msg->body);
	  size += pop_msg->size + 2;
	}
      delete_message(&pop_msg);
    }
  aggregator_integrity_buffer(buffer, msg);
}

char *aggregator_adddelim(char *body, int size)
{
  char *buffer;

  if ((buffer = malloc(sizeof(char) * (size + 5))) == NULL)
    return (NULL);
  bzero(buffer, size + 5);
  strcat(buffer, body);
  strcat(buffer, "\n");
  return (buffer);
}

void aggregator_integrity_msg(t_aggregator *aggr, char *sub, t_message *msg)
{
  msg->size = strlen(sub);
  msg->body = aggregator_adddelim(sub, msg->size);
  msg->size += 1;
  aggregator_integrity_sum(aggr, msg);
  free(msg->body);
  msg->body = NULL;
}

void aggregator_integrity_sub(t_aggregator *aggr, t_message *msg)
{
  char *sub;
  char *t[2];
  char *pos;
  char *sub_body;

  t[0] = strdup(msg->body);
  t[1] = t[0];
  if ((sub = strtok(msg->body, "\n")) != NULL)
    {
      aggregator_integrity_msg(aggr, sub, msg);
      while ((sub = strtok(NULL, "\n")))
	{
	  if ((sub_body = strstr(t[0], sub)) && (pos = strchr(sub_body, '\n')))
	    {
	      t[0] = pos + 1;
	      sub_body = aggregator_adddelim(sub, strlen(sub));
	      g_core.network->exec_queue->push_back
		(g_core.network->exec_queue, new_message(msg->to, sub_body));
	      free(sub_body);
	    }
	  else
	    aggr->queue->push_back(aggr->queue, new_message(msg->to, t[0]));
	}
    }
  free(t[1]);
}

void aggregator_integrity(t_aggregator *aggr, void *data)
{
  char *tmp;
  char *found;
  t_message *msg;

  msg = (void *)data;
  found = strchr(msg->body, '\n');
  if (msg && msg->body && found)
    {
      if ((found - (msg->body + strlen(msg->body) - 1)) == 0)
	{
	  aggregator_integrity_sum(aggr, msg);
	  delete_message(&msg);
	}
      else if (found - msg->body > 0)
	{
	  tmp = msg->body;
	  aggregator_integrity_sub(aggr, msg);
	  msg->body = tmp;
	  free(msg->body);
	  aggr->queue->erase(aggr->queue, msg, free);
	}
    }
}
