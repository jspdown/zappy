/*
** network_allocate.c for network_allocate in /home/antiqe/Documents/zappy/server/src/network
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri Jun 14 15:39:12 2013 ronan guiho
** Last update Wed Jul 10 12:49:29 2013 ronan guiho
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <strings.h>

#include "network/network.h"

t_network *new_network()
{
  t_network *net;

  if ((net = malloc(sizeof(t_network))) == NULL)
    return (NULL);
  bzero(&net->fdset, sizeof(fd_set));
  net->max_fd = -1;
  net->log = NULL;
  net->serv = NULL;
  net->list_client = NULL;
  return (net);
}

void delete_network(t_network *network)
{
  if (network)
    {
      if (network->serv)
	delete_network_server(network->serv);
      if (network->log)
	delete_logging_logger(network->log);
      if (network->list_client)
	delete_list(&network->list_client, free);
      if (network->exec_queue)
	delete_list(&network->exec_queue, free);
      if (network->send_queue)
	delete_list(&network->send_queue, free);
      if (network->array_player)
	free(network->array_player);
      free(network);
    }
}
