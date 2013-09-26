/*
** protocol_ressource.h for protocol_ressource in /home/antiqe/Documents/zappy/server/src/core/protocol
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Jul  9 16:24:39 2013 ronan guiho
** Last update Tue Jul  9 16:51:18 2013 ronan guiho
*/

#ifndef __PROTOCOL_RESSOURCE_H__
#define __PROTOCOL_RESSOURCE_H__

#include "player.h"
#include "action.h"

typedef struct s_proto_res t_proto_res;
struct s_proto_res
{
  int res;
  t_action_type action;
  t_player *player;
};

#endif
