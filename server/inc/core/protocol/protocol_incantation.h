/*
** protocol_incantation.h for protocol_incantation in /home/antiqe/Documents/zappy/server/src/core/protocol
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Jul  9 17:16:36 2013 ronan guiho
** Last update Thu Jul 11 11:44:22 2013 ronan guiho
*/

#ifndef __PROTCOL_INCANTATION_H__
#define __PROTCOL_INCANTATION_H__

typedef struct s_proto_inc t_proto_inc;
struct s_proto_inc
{
  unsigned int x;
  unsigned int y;
  char *buffer;
  int res;
  int size;
  int id;
};

#endif
