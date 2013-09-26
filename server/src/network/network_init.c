/*
** network_init.c for network_init in /home/antiqe/Documents/zappy/server/src/network
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri Jun 14 10:10:27 2013 ronan guiho
** Last update Mon Jul  8 10:36:39 2013 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "network/network.h"

int network_init_stream(t_network *net, short port)
{
  char buffer[256];
  t_log_message msg;

  init_logging_message(&msg, "Network",
		       "Initializing of Network Interfaces...",
		       NOTICE);
  network_logging(net->log, &msg);
  if ((net->serv = new_network_server(port, TCP)) == NULL)
    return (EXIT_FAILURE);
  if ((net->serv->run(net->serv)) == EXIT_FAILURE)
    {
      free(net->serv);
      init_logging_message(&msg, "Network", "Port already used", ERROR);
      network_logging(net->log, &msg);
      return (EXIT_FAILURE);
    }
  bzero(buffer, 256);
  sprintf(buffer, "Start listening on port : %d...", port);
  init_logging_message(&msg, "Network", buffer, NOTICE);
  network_logging(net->log, &msg);
  return (EXIT_SUCCESS);
}

int network_init_list_client(t_network *net)
{
  if ((net->list_client = new_list()) == NULL)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int network_init_network(t_network *net, short port)
{
  if (network_init_stream(net, port) == EXIT_FAILURE)
    {
      delete_logging_logger(net->log);
      free(net);
      return (EXIT_FAILURE);
    }
  net->max_fd = net->serv->sock[TCP] + 1;
  if (network_init_list_client(net) == EXIT_FAILURE)
    {
      delete_network_server(net->serv);
      delete_logging_logger(net->log);
      free(net);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

t_network *network_init(short port)
{
  t_network *net;

  if ((net = new_network()) == NULL)
    return (NULL);
  if (network_init_log(net) == EXIT_FAILURE)
    {
      free(net);
      return (NULL);
    }
  if (network_init_time(net) == EXIT_FAILURE)
    return (NULL);
  if (network_init_list(net) == EXIT_FAILURE)
    {
      free(net);
      free(net->exec_queue);
      free(net->send_queue);
    }
  if (network_init_network(net, port) == EXIT_FAILURE)
    return (NULL);
  return (net);
}
