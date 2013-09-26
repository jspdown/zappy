/*
** core_egg.c for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue Jul  9 12:04:07 2013 alexis leprovost
** Last update Tue Jul  9 12:05:21 2013 alexis leprovost
*/

#include <stdlib.h>

#include "core.h"
#include "list.h"
#include "extend.h"

t_bool	core_init_egg(t_core* core)
{
  t_log_message	msg;

  core->egg = new_list();
  if (!core->egg)
    init_logging_message(&msg, "Core",
			 "Eggs initialization failed", ERROR);
  else
    init_logging_message(&msg, "Core",
			 "Initializing of Eggs...", NOTICE);
  if (core->logger)
    core_logging(core->logger, &msg);
  return (core->egg ? TRUE : FALSE);
}
