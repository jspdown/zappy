/*
** network.h for network in /home/guiho_r/depot/zappy/server/src/network
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Jun  4 10:19:36 2013 ronan guiho
** Last update Thu Jul 11 21:04:36 2013 ronan guiho
*/

#ifndef __NETWORK_H__
#define __NETWORK_H__

#include <sys/time.h>

#include "option.h"
#include "logging/logger/logger.h"
#include "network/client/client.h"
#include "network/server/server.h"
#include "network/aggregator/aggregator.h"

#define NET_LOGGER_NAME			"root"
#define NET_CHANNEL_CONSOLE_NAME	"net_console"
#define NET_CHANNEL_FILE_NAME		"net_logfile"
#define NET_LOG_NAME			"log_network"

#define NET_CLIENT_AUGURY		500
#define NET_MSG_CONNECT			"BIENVENUE\n"

typedef struct s_network t_network;
struct s_network
{
  int max_fd;
  fd_set fdset;
  fd_set wfdset;
  fd_set cfdset[2];
  t_server *serv;
  t_list *list_client;
  t_logger *log;
  t_list *exec_queue;
  t_list *send_queue;
  t_player **array_player;
  unsigned int array_player_size;
};

t_network	*new_network();
void		delete_network(t_network *network);

t_network	*network_init(short port);
int		network_init_list(t_network *net);
int		network_init_time(t_network *net);
int		network_init_log(t_network *net);

void		network_mutiplexer_maxfd(void *data, void *cntx);
int		network_multiplexer(t_network *network, struct timeval* time_out);
void		network_multiplexer_deleteclient(t_player *player);
void		network_multiplexer_fdset_init(t_network *network);
void		network_multiplexer_acceptclient(t_network *network);
void		network_multiplexer_issetclient(void *data, void *set);
int		network_multiplexer_sendqueue_treatment();

t_logger	*network_logging_init();
void		network_logging(t_logger *log, t_log_message *msg);

#endif
