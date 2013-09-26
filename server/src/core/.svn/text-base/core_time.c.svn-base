/*
** core_time.c for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue Jul  2 13:55:35 2013 alexis leprovost
** Last update Thu Jul 11 18:17:07 2013 alexis leprovost
*/

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <sys/time.h>
#include <unistd.h>

#include "core.h"
#include "extend.h"
#include "action.h"
#include "list.h"

t_bool	core_init_time(t_core* core, t_opt* opt)
{
  t_log_message	msg;
  char		buffer[256];
  t_bool	ret;

  core->time =  opt ? atof(opt->value) : DEFAULT_TIME;
  bzero(buffer, 256);
  if (!(ret = core->time <= 0.0f ? FALSE : TRUE))
    {
      sprintf(buffer, "Time value '%.3f' denied", core->time);
      init_logging_message(&msg, "Core", buffer, ERROR);
    }
  else
    {
      core_init_table_time(core->time);
      core_init_table_part();
      sprintf(buffer, "Core cloaked on %.3f...", core->time);
      init_logging_message(&msg, "Core", buffer, NOTICE);
    }
  if (core->logger)
    core_logging(core->logger, &msg);
  return (ret);
}

void	core_maj_time(t_core* core, struct timeval* time_out)
{
  const double	ms = 1.0 / core->time;
  double	time;

  time = core->stack->time(core->stack);
  if ((int)time == -1)
    time = ms;
  time_out->tv_sec = (int)time;
  time_out->tv_usec = (int)((double)(time - (int)time) * 1000000);
}
