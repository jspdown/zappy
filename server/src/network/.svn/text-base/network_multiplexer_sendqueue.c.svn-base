/*
** network_multiplexer_sendqueue.c for network_multiplexer_sendqueue in /home/antiqe/Documents/zappy/server/src/network
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Jun 26 15:26:33 2013 ronan guiho
** Last update Sat Jul 13 12:33:58 2013 alexis leprovost
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#include "core/core.h"
#include "network/network.h"
#include "network/message/message.h"
#include "core/player/player.h"

t_core g_core;

void network_multiplexer_sendqueue_log(t_message* msg)
{
  char		buffer[256];
  t_log_message	lmsg;

  bzero(buffer, 256);
  sprintf(buffer, "{%d} Send message '", msg->to);
  strncat(buffer, msg->body, 64);
  if (strlen(msg->body) >= 64)
    strcat(buffer, "...'");
  else
    buffer[strlen(buffer) - 1] = '\'';
  init_logging_message(&lmsg, "Network",  buffer, NOTICE);
  network_logging(g_core.network->log, &lmsg);
}

void network_multiplexer_sendqueue_foreach(void *data, void *cntx)
{
  fd_set	*fdset;
  t_message	*msg;
  t_player	*player;

  fdset = (fd_set *)cntx;
  msg = (t_message *)data;
  if (msg)
    {
      player = g_core.network->array_player[msg->to];
      if (FD_ISSET(msg->to, &fdset[1]) && !FD_ISSET(msg->to, &fdset[0]))
	{
	  if (player && player->ctime == msg->ctime)
	    {
	      network_multiplexer_sendqueue_log(msg);
	      send(msg->to, msg->body, msg->size, MSG_NOSIGNAL);
	    }
	  g_core.network->send_queue->erase(g_core.network->send_queue,
					    msg, NULL);
	  delete_message(&msg);
	}
    }
}

int network_multiplexer_sendqueue_treatment()
{

  if (!g_core.network->send_queue->empty(g_core.network->send_queue))
    g_core.network->send_queue->foreach2(g_core.network->send_queue,
					 network_multiplexer_sendqueue_foreach,
					 &g_core.network->cfdset);
  return (EXIT_SUCCESS);
}
