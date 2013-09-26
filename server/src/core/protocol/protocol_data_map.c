/*
** protocol_data_map.c for protocol_data_map in /home/antiqe/Documents/zappy/server/src/core/protocol
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Jul  9 11:47:01 2013 ronan guiho
** Last update Sat Jul 13 13:21:46 2013 alexis leprovost
*/

#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "protocol.h"
#include "extend.h"
#include "level.h"
#include "core.h"

t_core	g_core;

t_bool protocol_data_map_treatement(t_core *core, t_action *action,
				    unsigned int *pos)
{
  char buffer[512];

  bzero(buffer, 512);
  if (!protocol_get_case(buffer, (unsigned int *)pos))
    return (protocol_send(core, action, "sbp\n"));
  protocol_send(core, action, buffer);
  return (TRUE);
}

t_bool protocol_data_map_chunk(t_core* core, t_player* player,
			       t_action* action)
{
  unsigned int	pos[2];
  char		b[64];

  if (!player || player->type != GRAPHIC)
    return (TRUE);
  pos[0] = atol(strtok((char*)action->data, " "));
  pos[1] = atol(strtok(NULL, " "));
  if (pos[0] == core->map->__width__)
    {
      pos[0] = 0;
      ++pos[1];
    }
  if (!(pos[1] == core->map->__height__))
    {
      if (!protocol_data_map_treatement(core, action, pos))
	return (FALSE);
      bzero(b, 64);
      ++pos[0];
      sprintf(b, "%d %d", pos[0], pos[1]);
      core->stack->set(core->stack,
		       protocol_create(DATA_MAP_CHUNK, action->index, b,
				       action->ctime));
    }
  return (TRUE);
}

t_bool protocol_data_map(t_core* core, t_player* player, t_action* action)
{
  char	b[4];

  if (!protocol_stack(core, player) || player->type != GRAPHIC)
    return (protocol_send(core, action, "ko\n"));
  bzero(b, 4);
  sprintf(b, "0 0");
  core->stack->set(core->stack,
		   protocol_create(DATA_MAP_CHUNK, action->index, b,
				   action->ctime));
  return (TRUE);
}

void protocol_data_map_notify(void* data)
{
  t_player*	player;
  t_action	action;

  player = (t_player*)data;
  if (player && player->type == GRAPHIC)
    {
      action.index = player->client->sock[TCP];
      action.ctime = player->ctime;
      protocol_data_map(&g_core, player, &action);
    }
}
