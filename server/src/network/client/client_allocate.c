/*
** client_allocate.c for client_allocate in /home/guiho_r/depot/zappy/dev/abs_network/client
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri May 31 14:54:05 2013 ronan guiho
** Last update Sat Jun  1 10:48:11 2013 ronan guiho
*/

#include <stdlib.h>
#include <strings.h>

#include "network/client/client.h"

void network_client_assign(t_client *client)
{
  client->get_socket = &network_client_get_socket;
  client->get_host = &network_client_get_host;
  client->get_protocol = &network_client_get_protocol;
  client->get_addr = &network_client_get_addr;
  client->connect = &network_client_connect;
  client->disconnect = &network_client_disconnect;
  client->send = &network_client_send;
  client->receive = &network_client_receive;
  client->send_to = &network_client_send_to;
  client->receive_from = &network_client_receive_from;
}

t_client *new_network_client(char *host, short port)
{
  t_client *client;
  struct hostent *shost;

  if ((client = malloc(sizeof(t_client))) == NULL)
    return (NULL);
  client->proto = NONE_PROTO;
  bzero(&client->saddr, sizeof(struct sockaddr_in));
  client->sock[TCP] = -1;
  client->sock[UDP] = -1;
  if ((shost = gethostbyname(host)))
    {
      client->saddr.sin_addr = *(struct in_addr *)shost->h_addr;
      client->saddr.sin_port = htons(port);
      client->saddr.sin_family = AF_INET;
      client->size_saddr = sizeof(client->saddr);
    }
  network_client_assign(client);
  return (client);
}

void delete_network_client(t_client *client)
{
  if (client)
    free(client);
}
