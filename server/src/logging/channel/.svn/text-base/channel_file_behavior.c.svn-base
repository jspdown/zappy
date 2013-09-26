/*
** channel_file_behavior.c for channel_file_behavior in /home/guiho_r/depot/zappy/server/inc/logging/channel
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sat Jun  1 10:21:19 2013 ronan guiho
** Last update Sun Jun  2 13:51:19 2013 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>

#include "logging/channel/channel_file.h"

const char *ref_fpriority[] =
{
  "Critical",
  "Debug",
  "Fatal",
  "Error",
  "Info",
  "Notice",
  "Trace",
  "Warning"
};

void logging_channel_file_write(t_channel_file *file, t_log_message *msg)
{
  struct tm *ltm;
  char buffer[512];

  bzero(buffer, 512);
  ltm = localtime(&msg->time);
  sprintf(buffer, "[%d/%d/%d %d:%d:%d] [%s] [%s] %s\n",
	  ltm->tm_mday, (1 + ltm->tm_mon),
	  (1900 + ltm->tm_year), ltm->tm_hour, (1 + ltm->tm_min),
	  (1 + ltm->tm_sec), ref_fpriority[msg->prio], msg->src, msg->text);
  write(file->fd, buffer, strlen(buffer));
}
