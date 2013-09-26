/*
** core_graphic.c for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue Jul  2 14:42:09 2013 alexis leprovost
** Last update Tue Jul  9 12:04:45 2013 alexis leprovost
*/

#include <stdlib.h>
#include <stdio.h>

#include "core.h"
#include "extend.h"

t_bool	core_init_graphic(t_core* core)
{
  t_log_message	msg;

  core->graphic = new_list();
  if (!core->graphic)
    init_logging_message(&msg, "Core",
			 "Graphical client initialization failed", ERROR);
  else
    init_logging_message(&msg, "Core",
			 "Initializing of Graphical Client...", NOTICE);
  if (core->logger)
    core_logging(core->logger, &msg);
  return (core->graphic ? TRUE : FALSE);
}

