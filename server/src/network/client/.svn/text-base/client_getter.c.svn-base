/*
** client_getter.c for client_getter in /home/guiho_r/depot/zappy/dev/abs_network/client
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri May 31 14:54:59 2013 ronan guiho
** Last update Sat Jun  1 10:48:49 2013 ronan guiho
*/

#include <stdlib.h>

#include "network/client/client.h"

int network_client_get_socket(t_client *client, t_net_proto proto)
{
  return ((proto == TCP) ? client->sock[TCP] : client->sock[UDP]);
}

char *network_client_get_host(t_client *client)
{
  return (inet_ntoa(client->saddr.sin_addr));
}

short network_client_get_port(t_client *client)
{
  return (ntohs(client->saddr.sin_port));
}

t_net_proto network_client_get_protocol(t_client *client)
{
  return (client->proto);
}

struct sockaddr_in *network_client_get_addr(t_client *client)
{
  return (&client->saddr);
}
