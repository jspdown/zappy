/*
** protocol_data_case.c for protocol_data_case in /home/antiqe/Documents/zappy/server/src/core/protocol
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Jul  8 17:07:06 2013 ronan guiho
** Last update Sat Jul 13 13:29:54 2013 alexis leprovost
*/

#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "protocol.h"
#include "extend.h"
#include "level.h"

t_core g_core;

t_bool	 protocol_get_case_player(t_player *ref, t_player *to)
{
  t_cell *cell;
  t_action action;
  char buffer[512];

  bzero(buffer, 512);
  action.index = to->client->sock[TCP];
  action.ctime = to->ctime;
  if ((cell = g_core.map->at(g_core.map, ref->x, ref->y)) == NULL)
    return (FALSE);
  sprintf(buffer, "bct %d %d %d %d %d %d %d %d %d\n",
	  ref->x, ref->y, (int)cell->ressources[0], (int)cell->ressources[1],
	  (int)cell->ressources[2], (int)cell->ressources[3],
	  (int)cell->ressources[4], (int)cell->ressources[5],
	  (int)cell->ressources[6]);
  return (protocol_send(&g_core, &action, buffer));
}

t_bool   protocol_get_case(char *buffer, unsigned int *pos)
{
  t_cell *cell;

  if ((cell = g_core.map->at(g_core.map, pos[0], pos[1])) == NULL)
    return (FALSE);
  sprintf(buffer, "bct %d %d %d %d %d %d %d %d %d\n",
	  pos[0], pos[1], (int)cell->ressources[0], (int)cell->ressources[1],
	  (int)cell->ressources[2], (int)cell->ressources[3],
	  (int)cell->ressources[4], (int)cell->ressources[5],
	  (int)cell->ressources[6]);
  return (TRUE);
}

t_bool protocol_data_case(t_core* core, t_player* player, t_action* action)
{
  char *elem;
  char buffer[512];
  unsigned int pos[2];

  if (!protocol_stack(core, player) || player->type != GRAPHIC)
    return (protocol_send(core, action, "ko\n"));
  if ((elem = strtok(action->data, "\n")) == NULL)
    return (protocol_send(core, action, "suc\n"));
  if ((elem = strtok(NULL, "\n")) == NULL)
    return (protocol_send(core, action, "sbp\n"));
  pos[0] = atoi(elem);
  if ((elem = strtok(NULL, "\n")) == NULL)
    return (protocol_send(core, action, "sbp\n"));
  pos[1] = atoi(elem);
  bzero(buffer, 256);
  if ((protocol_get_case(buffer, pos)) == FALSE)
    return (protocol_send(core, action, "sbp\n"));
  return (protocol_send(core, action, buffer));
}

void  protocol_data_case_notify(void *data, void *cntx)
{
  t_player *ref;
  t_player *to;

  ref = (t_player *)cntx;
  to = (t_player *)data;
  if (ref)
    protocol_get_case_player(ref, to);
}
