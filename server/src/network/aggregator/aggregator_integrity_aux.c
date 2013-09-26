/*
** aggregator_integrity_aux.c for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Sat Jul 13 12:37:13 2013 alexis leprovost
** Last update Sat Jul 13 12:37:43 2013 alexis leprovost
*/

#include <string.h>
#include <stdlib.h>

#include "core/core.h"
#include "network/message/message.h"
#include "network/aggregator/aggregator.h"

t_core g_core;

void aggregator_integrity_buffer(char *buffer, t_message *msg)
{
  if (buffer)
    {
      strcat(buffer, msg->body);
      g_core.network->exec_queue->
	push_back(g_core.network->exec_queue, new_message(msg->to, buffer));
      free(buffer);
    }
  else
    g_core.network->exec_queue->
      push_back(g_core.network->exec_queue, new_message(msg->to, msg->body));
}
