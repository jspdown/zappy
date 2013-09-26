/*
** Client.h for Client in /home/guiho_r/depot/zappy/dev/abs_network
**
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
**
** Started on  Fri May 31 14:17:26 2013 ronan guiho
** Last update Sat Jun  1 14:35:58 2013 ronan guiho
*/

#ifndef __CLIENT_H__
#define __CLIENT_H__

#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "network/protocol.h"

typedef struct s_client t_client;
struct s_client
{
  int sock[2];
  struct sockaddr_in saddr;
  socklen_t size_saddr;
  int proto;
  int (*get_socket)(t_client *, t_net_proto);
  char *(*get_host)(t_client *);
  short (*get_port)(t_client *);
  t_net_proto (*get_protocol)(t_client *);
  struct sockaddr_in *(*get_addr)(t_client *);
  int (*connect)(t_client *, t_net_proto);
  void (*disconnect)(t_client *);
  int (*send)(t_client *, void *, int);
  int (*receive)(t_client *, void *, int);
  int (*send_to)(t_client *, void *, int, t_client *);
  int (*receive_from)(t_client *, void *, int, t_client *);
};

t_client *new_network_client(char *, short);
void delete_network_client(t_client *);

int network_client_get_socket(t_client *, t_net_proto);
char *network_client_get_host(t_client *);
short network_client_get_port(t_client *);
t_net_proto network_client_get_protocol(t_client *);
struct sockaddr_in *network_client_get_addr(t_client *);
int network_client_connect(t_client *, t_net_proto);
void network_client_disconnect(t_client *);
int network_client_send(t_client *, void *, int);
int network_client_receive(t_client *, void *, int);
int network_client_send_to(t_client *, void *, int, t_client *);
int network_client_receive_from(t_client *, void *, int, t_client *);

#endif
