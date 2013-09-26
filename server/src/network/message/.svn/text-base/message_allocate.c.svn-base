/*
** message_allocate.c for message_allocate in /home/antiqe/Documents/zappy/server/src/network/message
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri Jun 21 15:05:13 2013 ronan guiho
** Last update Thu Jul 11 21:05:01 2013 ronan guiho
*/

#include <stdlib.h>
#include <string.h>

#include "core/core.h"
#include "core/player/player.h"
#include "network/message/message.h"

t_core g_core;

t_message *new_message(int to, char *body)
{
  t_message *msg;

  if ((msg = malloc(sizeof(t_message))) == NULL)
    return (NULL);
  msg->to = to;
  msg->ctime = g_core.network->array_player[to]->ctime;
  msg->body = strdup(body);
  msg->size = strlen(body);
  return (msg);
}

void delete_message(t_message **msg)
{
  if (*msg)
    {
      if ((*msg)->body)
	free((*msg)->body);
      free(*msg);
    }
}
