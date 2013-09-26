/*
** protocol_behaviour.c for protocol_behaviour in /home/antiqe/Documents/zappy/server/src/core/protocol
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Jul  2 10:57:33 2013 ronan guiho
** Last update Sat Jul 13 11:54:07 2013 alexis leprovost
*/

#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#include "stack.h"
#include "action.h"
#include "core/protocol/protocol.h"
#include "network/message/message.h"
#include "logging/logger/logger.h"

t_action*	protocol_create(t_action_type type, int index, char* body,
				time_t time)
{
  t_action*	action;

  if (!body || !(action = malloc(sizeof(t_action))))
    return (NULL);
  if (!(action->timer = new_timer()))
    {
      free(action);
      return (NULL);
    }
  if (!(action->data = strdup(body)))
    {
      delete_timer(&action->timer);
      free(action);
      return (NULL);
    }
  action->type = type;
  action->index = index;
  action->ctime = time;
  return (action);
}

t_action*	protocol_interpret(t_message *msg)
{
  int		i;
  t_action*	action;

  i = -1;
  if (!(action = protocol_create(SYNC, msg->to, msg->body, msg->ctime)))
    return (NULL);
  while (++i < PROTOCOL_MESSAGE_COUNT)
    if (!strncmp(msg->body, g_proto[i].name, g_proto[i].size) &&
	PROTOCOL_SEP(msg->body[g_proto[i].size]))
      {
	action->type = i;
	i = PROTOCOL_MESSAGE_COUNT;
      }
  return (action);
}

t_bool	protocol_exec(t_core* core, t_action *action)
{
  const t_action_func	func[MAX_ACTION_TYPE] = {
    &protocol_move, &protocol_right, &protocol_left,
    &protocol_see, &protocol_inventory, &protocol_take,
    &protocol_drop, &protocol_expulse, &protocol_broadcast,
    &protocol_incantation, &protocol_pre_fork, &protocol_connect_nbr,
    &protocol_map_size, &protocol_data_case, &protocol_data_map,
    &protocol_get_team, &protocol_pos_player, &protocol_level_player,
    &protocol_data_player, &protocol_get_time, &protocol_set_time,
    &protocol_death, &protocol_eclosion, &protocol_sync,
    &protocol_disconnect, &protocol_elevation, &protocol_corrupt,
    &protocol_win, &protocol_fork, &protocol_data_map_chunk
  };
  t_player*		player;

  if (action->index >= 0)
    player = core->network->array_player[action->index];
  else
    player = NULL;
  return (func[action->type](core, player, action));
}
