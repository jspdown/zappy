/*
** message.h for message in /home/guiho_r/depot/zappy/dev/log
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri May 31 18:58:27 2013 ronan guiho
** Last update Fri Jun 14 15:28:59 2013 ronan guiho
*/

#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include <time.h>

#define MESSAGE_TEXT_SIZE 512
#define MESSAGE_SRC_SIZE 64

typedef enum e_priority
{
  CRITICAL = 0,
  DEBUG,
  FATAL,
  ERROR,
  INFORMATION,
  NOTICE,
  TRACE,
  WARNING
} t_priority;

typedef struct s_log_message t_log_message;
struct s_log_message
{
  time_t time;
  t_priority prio;
  char src[MESSAGE_SRC_SIZE];
  char text[MESSAGE_TEXT_SIZE];
};

t_log_message *new_logging_message(char *src, char *text, t_priority prio);
void init_logging_message(t_log_message *msg, char *src, char *text,
			 t_priority prio);
void logging_message_delete(t_log_message *log);

#endif
