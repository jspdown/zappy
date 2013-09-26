/*
** channel_console_behavior.c for channel_console_behavior in /home/guiho_r/depot/zappy/server/inc/logging/channel
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sat Jun  1 10:08:30 2013 ronan guiho
** Last update Mon Jul  8 10:37:13 2013 ronan guiho
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "logging/channel/channel_console.h"

const char *ref_priority[] =
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

const char *ref_color[] =
{
  "\033[31;1m",
  "\033[35;1m",
  "\033[31;1m",
  "\033[31;1m",
  "\033[33;1m",
  "\033[32;1m",
  "\033[37;1m",
  "\033[33;1m"
};

void logging_channel_console_write(t_channel_console *console,
				   t_log_message *msg)
{
  struct tm *ltm;

  (void)console;
  ltm = localtime(&msg->time);
  printf("%s<%d/%d/%d %d:%d:%d> [%s] [%s] %s\033[0;40m\n",
	 ref_color[msg->prio], ltm->tm_mday, (1 + ltm->tm_mon),
	 (1900 + ltm->tm_year), ltm->tm_hour, (1 + ltm->tm_min),
	 (1 + ltm->tm_sec), ref_priority[msg->prio], msg->src, msg->text);
}
