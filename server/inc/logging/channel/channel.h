/*
** channel.h for channel in /home/guiho_r/depot/zappy/server/inc/logging/channel
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri May 31 21:45:58 2013 ronan guiho
** Last update Sat Jun  1 09:50:46 2013 ronan guiho
*/

#ifndef __CHANNEL_H__
#define __CHANNEL_H__

#include "logging/message/message.h"

#define CHANNEL_NAME_SIZE 64

typedef struct s_channel t_channel;
struct s_channel
{
  char name[CHANNEL_NAME_SIZE];
  void (*write)(t_channel *, t_log_message *);
};

#endif
