/*
** network_interruption.c for network_interruption in /home/antiqe/Documents/zappy/server/src/network
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri Jun 14 11:34:18 2013 ronan guiho
** Last update Wed Jun 19 11:53:01 2013 alexis leprovost
*/

#include <stdlib.h>
#include <strings.h>

#include "network/network.h"
#include "options/option.h"

void network_interruption_clear()
{
  if (g_network)
    delete_network(g_network);
  options_clear();
}

void network_interruption(int seg)
{
  t_log_message msg;

  (void)seg;
  init_logging_message(&msg, "Network", "Interruption by signal", FATAL);
  network_logging(g_network->log, &msg);
  g_network->serv->stop(g_network->serv);
  network_interruption_clear();
  exit(EXIT_SUCCESS);
}
