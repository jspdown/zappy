/*
** core_stack.c for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue Jul  2 14:44:28 2013 alexis leprovost
** Last update Tue Jul  2 14:53:56 2013 alexis leprovost
*/

#include <stdlib.h>
#include <stdio.h>

#include "core.h"
#include "extend.h"

t_bool	core_init_stack(t_core* core)
{
  t_log_message	msg;

  core->stack = new_stack();
  if (!core->stack)
    init_logging_message(&msg, "Core", "Stack initialization failed", ERROR);
  else
    init_logging_message(&msg, "Core", "Initializing of Stack...", NOTICE);
  if (core->logger)
    core_logging(core->logger, &msg);
  return (core->stack ? TRUE : FALSE);
}
