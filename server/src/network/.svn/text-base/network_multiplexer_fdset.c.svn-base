/*
** network_multiplexer_fdset.c for network_multiplexer_fdset in /home/antiqe/Documents/zappy/server/src/network
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri Jun 14 11:24:19 2013 ronan guiho
** Last update Thu Jul 11 13:14:35 2013 ronan guiho
*/

#include <stdlib.h>

#include "network/network.h"

void network_multiplexer_fdset_init(t_network *network)
{
  FD_ZERO(&network->fdset);
  FD_ZERO(&network->wfdset);
  FD_SET(network->serv->sock[TCP], &network->fdset);
  FD_SET(network->serv->sock[TCP], &network->wfdset);
}
