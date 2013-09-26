/*
** server.h for server in /home/guiho_r/depot/zappy/server/inc/network/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sat Jun  1 11:19:04 2013 ronan guiho
** Last update Fri Jun 14 13:05:15 2013 ronan guiho
*/

#ifndef __SERVER_H__
#define __SERVER_H__

#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "network/protocol.h"
#include "network/client/client.h"

typedef struct s_server t_server;
struct s_server
{
  int sock[2];
  int proto;
  struct sockaddr_in saddr;
  socklen_t size_saddr;
  int is_run;
  void (*stop)(t_server *);
  int (*is_running)(t_server *);
  int (*run)(t_server *);
  t_client *(*accept_connect)(t_server *);
};

t_server *new_network_server(short, int);
void delete_network_server(t_server *);

void network_interruption(int);
int network_server_run(t_server *);
void network_server_stop(t_server *);
t_client *network_server_accept(t_server *);
int network_server_is_running(t_server *);

#endif
