/*
** core_network.c for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue Jul  2 14:25:31 2013 alexis leprovost
** Last update Tue Jul  2 14:52:56 2013 alexis leprovost
*/

#include <stdlib.h>
#include <stdio.h>

#include "core.h"
#include "extend.h"

t_bool	core_init_network(t_core* core, t_opt* opt)
{
  t_log_message	msg;

  core->network = network_init(opt ? atoi(opt->value) : DEFAULT_PORT);
  if (!core->network)
    init_logging_message(&msg, "Core", "Network initialization failed", ERROR);
  else
    init_logging_message(&msg, "Core", "Initializing of Network...", NOTICE);
  if (core->logger)
    core_logging(core->logger, &msg);
  return (core->network ? TRUE : FALSE);
}
