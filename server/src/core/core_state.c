/*
** core_state.c for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue Jul  2 13:45:21 2013 alexis leprovost
** Last update Fri Jul 12 16:30:40 2013 alexis leprovost
*/

#include <stdlib.h>
#include <strings.h>
#include <stdio.h>

#include "core.h"
#include "extend.h"
#include "option.h"

t_bool	core_init_state(t_core* core, t_opt* opt)
{
  t_log_message	msg;
  char		buffer[256];

  core->max = opt ? atoi(opt->value) : DEFAULT_MAX;
  core->state = TRUE;
  bzero(buffer, 256);
  if ((int)core->max > 0)
    {
      sprintf(buffer, "Running... %ld players maximum to win", core->max);
      init_logging_message(&msg, "Core", buffer, NOTICE);
    }
  else
    {
      sprintf(buffer, "Win condition '%ld' denied", core->max);
      init_logging_message(&msg, "Core", buffer, ERROR);
    }
  if (core->logger)
    core_logging(core->logger, &msg);
  return ((int)core->max > 0);
}
