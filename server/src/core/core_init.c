/*
** core_init.c for core_init in /home/antiqe/Documents/zappy/server/src/core
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri Jun 14 16:02:57 2013 ronan guiho
** Last update Tue Jul  9 12:03:35 2013 alexis leprovost
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <strings.h>
#include <string.h>

#include "logging/logger/logger.h"
#include "core.h"
#include "extend.h"
#include "option.h"
#include "team.h"
#include "stack.h"

int core_init(t_core* core)
{
  t_log_message msg;
  t_bool	ret;

  if (!core)
    return (EXIT_FAILURE);
  signal(SIGINT, core_interruption);
  signal(SIGTERM, core_interruption);
  ret = core_init_logger(core) &
    core_init_state(core, options_get(OPT_MAX)) &
    core_init_time(core, options_get(OPT_DELAY)) &
    core_init_map(core) &
    core_init_network(core, options_get(OPT_PORT)) &
    core_init_pool(core) &
    core_init_team(core) &
    core_init_graphic(core) &
    core_init_stack(core) &
    core_init_egg(core);
  if (!ret)
    {
      init_logging_message(&msg, "Core", "Initialization failed", FATAL);
      core_logging(core->logger, &msg);
      core_delete(core);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
