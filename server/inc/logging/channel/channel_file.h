/*
** channel_file.h for channel_file in /home/guiho_r/depot/zappy/server/inc/logging/channel
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sat Jun  1 10:18:46 2013 ronan guiho
** Last update Tue Jun  4 10:27:14 2013 ronan guiho
*/

#ifndef __CHANNEL_FILE_H__
#define __CHANNEL_FILE_H__

#include "logging/message/message.h"

#define CHANNEL_NAME_SIZE 64

typedef struct s_channel_file t_channel_file;
struct s_channel_file
{
  char name[CHANNEL_NAME_SIZE];
  void (*write)(t_channel_file *, t_log_message *);
  int fd;
};

t_channel_file *new_logging_channel_file(char *, char *);

void logging_channel_file_write(t_channel_file *, t_log_message *);

#endif
