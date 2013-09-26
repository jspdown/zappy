/*
** protocol_get_team.c for protocol_get_team in /home/antiqe/Documents/zappy/server/src/core/protocol
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Jul  9 11:47:50 2013 ronan guiho
** Last update Tue Jul  9 12:55:07 2013 ronan guiho
*/

#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "protocol.h"
#include "extend.h"
#include "level.h"

t_core g_core;

void   protocol_foreach_team(void *data, void *cntx)
{
  t_team *team;
  t_action *action;
  char buffer[512];

  team = (t_team *)data;
  action = (t_action *)cntx;
  if (team && team->name)
    {
      bzero(buffer, 512);
      sprintf(buffer, "tna %s\n", team->name);
      protocol_send(&g_core, action, buffer);
    }
}

t_bool protocol_get_team(t_core* core, t_player* player, t_action* action)
{
  if (!protocol_stack(core, player) || player->type != GRAPHIC)
    return (protocol_send(core, action, "ko\n"));
  core->team->foreach2(core->team, protocol_foreach_team, action);
  return (TRUE);
}
