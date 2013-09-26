/*
** core_pool.c for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue Jul  2 14:37:51 2013 alexis leprovost
** Last update Mon Jul  8 17:05:18 2013 alexis leprovost
*/

#include <stdlib.h>
#include <stdio.h>

#include "core.h"
#include "extend.h"

t_bool	core_init_pool(t_core* core)
{
  t_log_message	msg;

  core->pool = new_uuid();
  if (!core->pool)
    init_logging_message(&msg, "Core", "ID initialization failed", ERROR);
  else
    init_logging_message(&msg, "Core", "Initializing of ID...", NOTICE);
  if (core->logger)
    core_logging(core->logger, &msg);
  return (core->pool ? TRUE : FALSE);
}
