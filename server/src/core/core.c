/*
** core.c for core in /home/guiho_r/depot/zappy/server/src/core
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Jun  4 10:06:32 2013 ronan guiho
** Last update Sat Jul 13 11:21:42 2013 alexis leprovost
*/

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

#include "option.h"
#include "network.h"
#include "core.h"
#include "map.h"
#include "extend.h"

t_core	g_core;

void	core_interruption(int seg)
{
  t_log_message msg;

  (void)seg;
  printf("\b\b");
  init_logging_message(&msg, "Core", "Interruption by signal", FATAL);
  core_logging(g_core.logger, &msg);
  g_core.state = FALSE;
}

int core_run(char **av)
{
  struct timeval	time_out;

  if ((core_options(av)) == EXIT_FAILURE || core_init(&g_core) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  network_multiplexer_fdset_init(g_core.network);
  bzero(&time_out, sizeof(struct timeval));
  if ((g_core.state = core_generate_world(&g_core)))
    g_core.state = core_generate_id(&g_core);
  while (g_core.state)
    {
      core_maj_time(&g_core, &time_out);
      network_multiplexer(g_core.network, &time_out);
      core_exec(&g_core);
      if (!g_core.network->send_queue->empty(g_core.network->send_queue))
	network_multiplexer_sendqueue_treatment();
    }
  g_core.network->serv->stop(g_core.network->serv);
  core_delete(&g_core);
  options_clear();
  return (EXIT_SUCCESS);
}
