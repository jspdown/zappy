/*
** channel_console_allocate.c for channel_console_allocate in /home/guiho_r/depot/zappy/server/inc/logging/channel
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sat Jun  1 09:58:05 2013 ronan guiho
** Last update Tue Jun  4 10:26:28 2013 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>

#include "logging/channel/channel_console.h"

void logging_channel_console_assign(t_channel_console *console)
{
  console->write = &logging_channel_console_write;
}

t_channel_console *new_logging_channel_console(char *name)
{
  t_channel_console *console;

  if ((console = malloc(sizeof(t_channel_console))) == NULL)
    return (NULL);
  sprintf(console->name, "%s", name);
  logging_channel_console_assign(console);
  return (console);
}
