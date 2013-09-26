/*
** client_behaviour.c for client_behaviour in /home/guiho_r/depot/zappy/dev/abs_network/client
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri May 31 14:58:54 2013 ronan guiho
** Last update Thu Jul 11 16:03:23 2013 alexis leprovost
*/

#include <stdlib.h>
#include <unistd.h>

#include "network/client/client.h"

int network_client_connect(t_client *client, t_net_proto proto)
{
  client->proto = proto;
  if (proto == TCP || proto == (TCP | UDP))
    {
      if (((client->sock[TCP] = socket(AF_INET, SOCK_STREAM, 0)) == -1) ||
	  (connect(client->sock[TCP], (struct sockaddr *)&client->saddr,
		   sizeof(struct sockaddr))) == -1)
	return (EXIT_FAILURE);
    }
  else if (proto == UDP || proto == (TCP | UDP))
    if ((client->sock[UDP] = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
      return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

void network_client_disconnect(t_client *client)
{
  close(client->sock[TCP]);
}
