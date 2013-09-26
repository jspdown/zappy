/*
** server_allocate.c for server_allocate in /home/guiho_r/depot/zappy/server/src/network/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Jun  2 11:53:09 2013 ronan guiho
** Last update Tue Jun  4 10:49:26 2013 ronan guiho
*/

#include <stdlib.h>

#include "network/server/server.h"

void network_server_assign(t_server *server)
{
  server->run = &network_server_run;
  server->stop = &network_server_stop;
  server->is_running = &network_server_is_running;
  server->accept_connect = &network_server_accept;
}

t_server *new_network_server(short port, int proto)
{
  t_server *server;

  if ((server = malloc(sizeof(t_server))) == NULL)
    return (NULL);
  server->is_run = 0;
  server->sock[TCP] = -1;
  server->sock[UDP] = -1;
  server->proto = proto;
  server->saddr.sin_addr.s_addr = htonl(INADDR_ANY);
  server->saddr.sin_family = AF_INET;
  server->saddr.sin_port = htons(port);
  network_server_assign(server);
  return (server);
}

void delete_network_server(t_server *server)
{
  if (server)
    free(server);
}
