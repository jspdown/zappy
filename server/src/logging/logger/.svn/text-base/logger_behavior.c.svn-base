/*
** logger_behavior.c for logger_behavior in /home/guiho_r/depot/zappy/server/src/logging/logger
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sat Jun  1 10:28:08 2013 ronan guiho
** Last update Mon Jul  8 10:37:43 2013 ronan guiho
*/

#include <stdlib.h>

#include "logging/logger/logger.h"
#include "logging/channel/channel.h"

void logging_logger_log_foreach(void *data, void *context)
{
  t_channel *chan;

  chan = (t_channel *)data;
  chan->write(data, context);
}

void logging_logger_log(t_logger *log, t_log_message *msg)
{
  log->channels->foreach2(log->channels,
			  logging_logger_log_foreach, msg);
}
