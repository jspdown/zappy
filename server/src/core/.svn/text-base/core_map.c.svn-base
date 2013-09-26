/*
** core_map.c for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue Jul  2 14:19:30 2013 alexis leprovost
** Last update Tue Jul  2 14:51:59 2013 alexis leprovost
*/

#include <stdlib.h>
#include <stdio.h>

#include "core.h"
#include "extend.h"

t_bool	core_init_map(t_core* core)
{
  t_log_message	msg;

  if (!(core->map = new_map()))
    init_logging_message(&msg, "Core", "World initialization failed", ERROR);
  else
    init_logging_message(&msg, "Core", "Initializing of World...", NOTICE);
  if (core->logger)
    core_logging(core->logger, &msg);
  return (TRUE);
}
