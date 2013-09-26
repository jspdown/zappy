/*
** protocol_map_size.c for protocol_map_size in /home/antiqe/Documents/zappy/server/src/core/protocol
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Jul  8 17:05:32 2013 ronan guiho
** Last update Thu Jul 11 16:02:32 2013 alexis leprovost
*/

#include <stdlib.h>
#include <strings.h>

#include "protocol.h"
#include "extend.h"
#include "level.h"

t_bool protocol_map_size(t_core* core, t_player* player, t_action* action)
{
  char buffer[128];

  if (!protocol_stack(core, player) || player->type != GRAPHIC)
    return (protocol_send(core, action, "ko\n"));
  bzero(buffer, 128);
  sprintf(buffer, "msz %d %d\n", (int)core->map->__width__,
	  (int)core->map->__height__);
  return (protocol_send(core, action, buffer));
}
