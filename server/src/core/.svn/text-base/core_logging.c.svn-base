/*
** core_logging.c for core_logging in /home/antiqe/Documents/zappy/server/src/core
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri Jun 14 16:21:45 2013 ronan guiho
** Last update Wed Jul 10 12:54:16 2013 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "core/core.h"
#include "options/option.h"
#include "logging/logger/logger.h"
#include "extend.h"

void core_logging(t_logger *log, t_log_message *msg)
{
  if (options_get(OPT_VERBOSE) ||
      msg->prio == FATAL || msg->prio == ERROR)
    log->log(log, msg);
}

t_bool	core_init_logger(t_core* core)
{
  t_log_message	msg;

  if (!(core->logger = new_logging_logger(CORE_LOGGER_NAME)))
    return (FALSE);
  core->logger->add_channel(core->logger,
			    new_logging_channel_console(CORE_CHANNEL_CONSOLE_NAME));
  core->logger->add_channel(core->logger,
			    new_logging_channel_file(CORE_CHANNEL_FILE_NAME,
						     CORE_LOG_NAME));
  init_logging_message(&msg, "Core", "Initializing of Logging Manager...",
		       NOTICE);
  core_logging(core->logger, &msg);
  return (TRUE);
}
