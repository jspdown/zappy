/*
** channel_file_allocate.c for channel_file_allocate in /home/guiho_r/depot/zappy/server/inc/logging/channel
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sat Jun  1 10:20:16 2013 ronan guiho
** Last update Tue Jun  4 10:26:38 2013 ronan guiho
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "logging/channel/channel_file.h"

void logging_channel_file_assign(t_channel_file *file)
{
  file->write = &logging_channel_file_write;
}

t_channel_file *new_logging_channel_file(char *name, char *filename)
{
  t_channel_file *file;

  if ((file = malloc(sizeof(t_channel_file))) == NULL)
    return (NULL);
  if ((file->fd = open(filename, O_CREAT | O_APPEND | O_WRONLY,
		       S_IRUSR | S_IWUSR)) == -1)
    {
      free(file);
      return (NULL);
    }
  sprintf(file->name, name);
  logging_channel_file_assign(file);
  return (file);
}
