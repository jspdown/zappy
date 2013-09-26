/*
** logger_allocate.c for logger_allocate in /home/guiho_r/depot/zappy/server/src/logging/logger
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri May 31 21:10:37 2013 ronan guiho
** Last update Fri Jun 14 13:24:23 2013 ronan guiho
*/

#include <stdlib.h>
#include <stdio.h>

#include "list.h"
#include "logging/logger/logger.h"

void logging_logger_assign(t_logger *log)
{
  log->add_channel = &logging_logger_add_channel;
  log->delete_channel = &logging_logger_delete_channel;
  log->get_channel = &logging_logger_get_channel;
  log->log = &logging_logger_log;
}

t_logger *new_logging_logger(char *name)
{
  t_logger *log;

  if ((log = malloc(sizeof(t_logger))) == NULL)
    return (NULL);
  sprintf(log->name, "%s", name);
  if ((log->channels = new_list()) == NULL)
    return (NULL);
  logging_logger_assign(log);
  return (log);
}

void delete_logging_logger(t_logger *log)
{
  if (log)
    {
      if (log->channels)
	{
	  log->channels->clear(log->channels, free);
	  delete_list(&log->channels, free);
	}
      free(log);
    }
}
