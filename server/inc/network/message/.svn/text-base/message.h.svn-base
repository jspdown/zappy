/*
** message.h for message in /home/antiqe/Documents/zappy/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri Jun 21 15:03:42 2013 ronan guiho
** Last update Thu Jul 11 21:04:43 2013 ronan guiho
*/

#ifndef __MESSAGE_NETWORK_H__
#define __MESSAGE_NETWORK_H__

#include <time.h>

typedef struct s_player t_player;
typedef struct s_message t_message;
struct s_message
{
  int to;
  time_t ctime;
  char *body;
  int size;
};

t_message	*new_message(int to, char *body);
void		delete_message(t_message **msg);

#endif
