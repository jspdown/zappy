/*
** protocol_send.c for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Jul  5 01:18:15 2013 alexis leprovost
** Last update Fri Jul 12 16:06:45 2013 alexis leprovost
*/

#include <stdlib.h>
#include <string.h>

#include "protocol.h"
#include "player.h"
#include "core.h"
#include "network/message/message.h"

t_bool	protocol_send(t_core* core, t_action* action, char* body)
{
  t_message*	msg;

  if ((msg = malloc(sizeof(t_message))) == NULL)
    return (FALSE);
  msg->to = action->index;
  msg->ctime = action->ctime;
  if ((msg->body = strdup(body)) == NULL)
    {
      free(msg);
      return (FALSE);
    }
  msg->size = strlen(body);
  core->network->send_queue->push_back(core->network->send_queue,
				       (void*)msg);
  return (TRUE);
}
