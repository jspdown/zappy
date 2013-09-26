/*
** core_exec.c for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue Jul  2 16:20:50 2013 alexis leprovost
** Last update Sat Jul 13 12:34:20 2013 alexis leprovost
*/

#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "core.h"
#include "protocol.h"
#include "network/message/message.h"
#include "action.h"
#include "extend.h"

t_core	g_core;

double	g_ref_action[MAX_ACTION_TYPE][2];

void		core_delete_action(t_action **action)
{
  if (*action)
    {
      if ((*action)->data)
	free((*action)->data);
      if ((*action)->timer)
	delete_timer(&(*action)->timer);
      free(*action);
      action = NULL;
    }
}

void		core_exec_queue_log(t_message* msg)
{
  char		buffer[256];
  t_log_message	lmsg;

  bzero(buffer, 256);
  sprintf(buffer, "{%d} Receive message '", msg->to);
  strncat(buffer, msg->body, 64);
  if (strlen(msg->body) >= 64)
    strcat(buffer, "...'");
  else
    buffer[strlen(buffer) - 1] = '\'';
  init_logging_message(&lmsg, "Network",  buffer, NOTICE);
  network_logging(g_core.network->log, &lmsg);
}

static t_bool	core_exec_queue(t_core* c)
 {
  t_message*	m;
  t_player*	player;
  t_action*	action;

  while ((m = c->network->exec_queue->pop_front(c->network->exec_queue)))
    {
      core_exec_queue_log(m);
      if ((player = c->network->array_player[m->to]) &&
	  (action = protocol_interpret(m)))
	{
	  if (action->type != SYNC && player->type == UNKNOWN)
	    action->type = SYNC;
	  if (player->action->size(player->action) < ACTION_MAX ||
	      player->type != BOT)
	    {
	      if (player->action->empty(player->action))
		c->stack->set(c->stack, action);
	      player->action->push_back(player->action, action);
	    }
	  else
	    core_delete_action(&action);
	}
      delete_message(&m);
    }
  return (TRUE);
}

static t_bool	core_exec_action(t_core* core)
{
  size_t	lim;
  t_action*	action;
  t_player*	player;

  lim = ACTION_MAX + 1;
  while (core->stack->ready(core->stack) && --lim)
    if ((action = core->stack->get(core->stack)))
      {
	if (!protocol_exec(core, action) && action->index >= 0 &&
	    (player = core->network->array_player[action->index]))
	  ++player->error;
	core_delete_action(&action);
      }
  return (TRUE);
}

t_bool	core_exec(t_core* core)
{
  return (core_exec_queue(core) & core_exec_action(core));
}
