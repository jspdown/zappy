/*
** network_init_sub.c for network_init_sub in /home/antiqe/Documents/zappy/server/src/network
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Jul  8 10:31:30 2013 ronan guiho
** Last update Mon Jul  8 10:34:40 2013 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "network/network.h"

int network_init_list(t_network *net)
{
  if ((net->exec_queue = new_list()) == NULL)
    return (EXIT_FAILURE);
  if ((net->send_queue = new_list()) == NULL)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int network_init_time(t_network *net)
{
  int i;

  i = -1;
  if ((net->array_player = malloc(sizeof(t_player *) *
				  NET_CLIENT_AUGURY)) == NULL)
    return (EXIT_FAILURE);
  while (++i < NET_CLIENT_AUGURY)
    net->array_player[i] = NULL;
  net->array_player_size = NET_CLIENT_AUGURY;
  return (EXIT_SUCCESS);
}

int network_init_log(t_network *net)
{
  t_log_message msg;

  if ((net->log = network_logging_init()) == NULL)
    return (EXIT_FAILURE);
  init_logging_message(&msg, "Network", "Initializing of Logging Manager...",
		       NOTICE);
  network_logging(net->log, &msg);
  return (EXIT_SUCCESS);
}
