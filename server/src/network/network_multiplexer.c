/*
** network_multiplexer.c for network_multiplexer in /home/guiho_r/depot/zappy/server/src/core
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Jun  4 18:03:08 2013 ronan guiho
** Last update Sat Jul 13 10:54:29 2013 alexis leprovost
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "core/core.h"
#include "network/network.h"

t_core g_core;

int network_multiplexer(t_network *network, struct timeval* time_out)
{
  network->cfdset[0] = network->fdset;
  if (!network->send_queue->empty(network->send_queue))
    network->cfdset[1] = network->wfdset;
  else
    FD_ZERO(&network->cfdset[1]);
  if (select(network->max_fd, &network->cfdset[0],
	     &network->cfdset[1], NULL, time_out) > 0)
    {
      if (FD_ISSET(network->serv->sock[TCP], &network->cfdset[0]))
	network_multiplexer_acceptclient(network);
      else
	network->list_client->foreach2(network->list_client,
				       network_multiplexer_issetclient,
				       &network->cfdset[0]);
    }
  return (EXIT_SUCCESS);
}
