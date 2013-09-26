/*
** protocol_get_time.c for protocol_get_time in /home/antiqe/Documents/zappy/server/src/core/protocol
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Jul  8 17:09:19 2013 ronan guiho
** Last update Wed Jul 10 11:38:09 2013 ronan guiho
*/

#include <stdlib.h>
#include <strings.h>

#include "protocol.h"
#include "extend.h"
#include "level.h"

t_bool protocol_get_time(t_core* core, t_player* player, t_action* action)
{
  char buffer[512];

  if (!protocol_stack(core, player) || player->type != GRAPHIC)
    return (protocol_send(core, action, "ko\n"));
  bzero(buffer, 512);
  sprintf(buffer, "sgt %d\n", (int)core->time);
  return (protocol_send(core, action, buffer));
}
