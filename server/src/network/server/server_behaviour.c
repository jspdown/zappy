/*
** server_behaviour.c for server_behaviour in /home/guiho_r/depot/zappy/server/src/network/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Jun  2 11:58:26 2013 ronan guiho
** Last update Thu Jul 11 16:06:26 2013 alexis leprovost
*/

#include <stdlib.h>

#include "network/server/server.h"

int network_server_run(t_server *server)
{
  if (server->proto == TCP || (server->proto == (TCP | UDP)))
    {
      if ((server->sock[TCP] = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	return (EXIT_FAILURE);
      if ((bind(server->sock[TCP], (struct sockaddr *)&(server->saddr),
		sizeof(server->saddr))) == -1)
	return (EXIT_FAILURE);
      listen(server->sock[TCP], 1000);
    }
  if (server->proto == UDP || (server->proto == (TCP | UDP)))
    {
      if ((server->sock[UDP] = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
	return (EXIT_FAILURE);
      if ((bind(server->sock[UDP], (struct sockaddr *)&(server->saddr),
		sizeof(server->saddr))) == -1)
	return (EXIT_FAILURE);
    }
  server->is_run = 1;
  return (EXIT_SUCCESS);
}

int network_server_is_running(t_server *server)
{
  return (server->is_run);
}

void network_server_stop(t_server *server)
{
  if (server->sock[TCP] != -1)
    shutdown(server->sock[TCP], 2);
  if (server->sock[UDP] != -1)
    shutdown(server->sock[UDP], 2);
}

t_client *network_server_accept(t_server *server)
{
  int sock;
  t_client *client;
  socklen_t size_saddr;
  struct sockaddr_in saddr;

  size_saddr = sizeof(saddr);
  if ((sock = \
       accept(server->sock[TCP], (struct sockaddr *)&saddr, &size_saddr)) == \
      -1)
    return (NULL);
  if ((client = new_network_client(inet_ntoa(saddr.sin_addr), \
				   ntohs(saddr.sin_port))) == NULL)
    return (NULL);
  client->sock[TCP] = sock;
  return (client);
}
