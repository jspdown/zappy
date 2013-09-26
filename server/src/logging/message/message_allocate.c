/*
** message_allocate.c for message_allocate in /home/guiho_r/depot/zappy/dev/log
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri May 31 20:19:47 2013 ronan guiho
** Last update Tue Jun  4 10:47:33 2013 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "logging/message/message.h"

t_log_message *new_logging_message(char *src, char *text, t_priority prio)
{
  t_log_message *msg;

  if ((msg = malloc(sizeof(t_log_message))) == NULL)
    return (NULL);
  time(&msg->time);
  msg->prio = prio;
  sprintf(msg->src, "%s", src);
  sprintf(msg->text, "%s", text);
  return (msg);
};

void init_logging_message(t_log_message *msg, char *src, char *text, \
			  t_priority prio)
{
  bzero(msg, sizeof(t_log_message));
  time(&msg->time);
  msg->prio = prio;
  sprintf(msg->src, "%s", src);
  sprintf(msg->text, "%s", text);
}

void logging_message_delete(t_log_message *msg)
{
  if (msg)
    free(msg);
}
