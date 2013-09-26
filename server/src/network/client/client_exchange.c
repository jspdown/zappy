/*
** client_exchange.c for client_exchange in /home/guiho_r/depot/zappy/dev/abs_network/client
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri May 31 15:34:56 2013 ronan guiho
** Last update Thu Jul 11 16:03:41 2013 alexis leprovost
*/

#include <stdlib.h>

#include "network/client/client.h"

int network_client_send(t_client *client, void *data, int size)
{
  return (send(client->sock[TCP], data, size, 0));
}

int network_client_receive(t_client *client, void *data, int size)
{
  return (recv(client->sock[TCP], data, size, 0));
}

int network_client_send_to(t_client *from, void *data, int size, t_client *to)
{
  return (sendto(from->sock[UDP], data, size,
		 0, (struct sockaddr *)&to->saddr, to->size_saddr));
}

int network_client_receive_from(t_client *from, void *data, int size,
				t_client *to)
{
  return (recvfrom(from->sock[UDP], data, size, 0,
		   (struct sockaddr *)&to->saddr, &to->size_saddr));
}
