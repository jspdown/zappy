/*
** channel_console.h for channel_console in /home/guiho_r/depot/zappy/server/inc/logging/channel
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri May 31 21:52:26 2013 ronan guiho
** Last update Tue Jun  4 10:26:51 2013 ronan guiho
*/

#ifndef __CHANNEL_CONSOLE_H__
#define __CHANNEL_CONSOLE_H__

#include "logging/message/message.h"

#define CHANNEL_NAME_SIZE 64

typedef struct s_channel_console t_channel_console;
struct s_channel_console
{
  char name[CHANNEL_NAME_SIZE];
  void (*write)(t_channel_console *, t_log_message *);
};

t_channel_console *new_logging_channel_console(char *);

void logging_channel_console_write(t_channel_console *, t_log_message *);

#endif
