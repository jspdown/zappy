/*
** network_log.c for network_log in /home/guiho_r/depot/zappy/server/src/network
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Jun  4 10:15:36 2013 ronan guiho
** Last update Wed Jul 10 12:53:34 2013 ronan guiho
*/

#include <stdlib.h>

#include "network/network.h"

t_opt_c *g_opt;

t_logger *network_logging_init()
{
  t_logger *logger;

  if ((logger = new_logging_logger(NET_LOGGER_NAME)) == NULL)
    return (NULL);
  logger->add_channel(logger,
		      new_logging_channel_console(NET_CHANNEL_CONSOLE_NAME));
  logger->add_channel(logger,
		      new_logging_channel_file(NET_CHANNEL_FILE_NAME,
					       NET_LOG_NAME));
  return (logger);
}

void network_logging(t_logger *log, t_log_message *msg)
{
  if (options_get(OPT_VERBOSE) ||
      msg->prio == FATAL || msg->prio == ERROR)
    log->log(log, msg);
}
