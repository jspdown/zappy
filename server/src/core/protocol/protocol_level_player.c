/*
** protocol_level_player.c for protocol_level_player in /home/antiqe/Documents/zappy/server/src/core/protocol
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Jul  8 17:08:17 2013 ronan guiho
** Last update Thu Jul 11 13:48:13 2013 ronan guiho
*/

#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "protocol.h"
#include "extend.h"
#include "level.h"

t_core g_core;

t_bool protocol_level_player_aux(t_player *player, t_player *to)
{
  t_action action;
  char buffer[512];

  action.index = to->client->sock[TCP];
  action.ctime = to->ctime;
  bzero(buffer, 512);
  sprintf(buffer, "plv %d %d\n", (int)player->id, player->level);
  return (protocol_send(&g_core, &action, buffer));
}

t_bool protocol_level_player(t_core* core, t_player* player, t_action* action)
{
  int id;
  char *elem;
  char buffer[512];

  if (!protocol_stack(core, player) || player->type != GRAPHIC)
    return (protocol_send(core, action, "ko\n"));
  if ((elem = strtok(action->data, "\n")) == NULL)
    return (protocol_send(core, action, "suc\n"));
  if ((elem = strtok(NULL, "\n")) == NULL)
    return (protocol_send(core, action, "sbp\n"));
  id = atoi(elem);
  if ((player =
       core->network->list_client->find_if(core->network->list_client,
					   &id,
					   protocol_get_player_by_id)) != NULL)
    {
      bzero(buffer, 512);
      sprintf(buffer, "plv %d %d\n", (int)player->id, player->level);
      return (protocol_send(core, action, buffer));
    }
  return (protocol_send(core, action, "sbp\n"));
}

void protocol_level_player_notify(void *data, void *cntx)
{
  t_player *ref;
  t_player *to;

  ref = (t_player *)cntx;
  to = (t_player *)data;
  if (ref)
    protocol_level_player_aux(ref, to);
}
