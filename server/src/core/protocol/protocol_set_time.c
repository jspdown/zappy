/*
** protocol_set_time.c for protocol_set_time in /home/antiqe/Documents/zappy/server/src/core/protocol
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Jul  8 17:09:55 2013 ronan guiho
** Last update Fri Jul 12 16:21:49 2013 alexis leprovost
*/

#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "protocol.h"
#include "extend.h"
#include "level.h"

t_bool protocol_set_time(t_core* core, t_player* player, t_action* action)
{
  char *elem;
  char buffer[512];

  if (!protocol_stack(core, player) || player->type != GRAPHIC)
    return (protocol_send(core, action, "ko\n"));
  if ((elem = strtok(action->data, " ")) == NULL)
    return (protocol_send(core, action, "suc\n"));
  if ((elem = strtok(NULL, "\n")) == NULL)
    return (protocol_send(core, action, "sbp\n"));
  core->time = atof(elem);
  core_init_table_time(core->time);
  bzero(buffer, 512);
  sprintf(buffer, "sgt %d\n", (int)core->time);
  return (protocol_send(core, action, buffer));
}
