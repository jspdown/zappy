/*
** logger.h for logger in /home/guiho_r/depot/zappy/dev/log
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri May 31 18:35:52 2013 ronan guiho
** Last update Fri Jun 14 13:15:51 2013 ronan guiho
*/

#ifndef __LOGGER_H__
#define __LOGGER_H__

#include "list.h"
#include "logging/message/message.h"
#include "logging/channel/channel_console.h"
#include "logging/channel/channel_file.h"

#define LOGGER_NAME_SIZE 64

typedef struct s_logger t_logger;
struct s_logger
{
  char name[LOGGER_NAME_SIZE];
  t_list *channels;
  void (*add_channel)(t_logger *, void *);
  int (*delete_channel)(t_logger *, char *);
  void *(*get_channel)(t_logger *, char *);
  void (*log)(t_logger *, t_log_message *);
};

t_logger *new_logging_logger(char *);
void delete_logging_logger(t_logger *);

void logging_logger_add_channel(t_logger *, void *);
int logging_logger_delete_channel(t_logger *, char *);
void *logging_logger_get_channel(t_logger *, char *);

void logging_logger_log(t_logger *, t_log_message *);

#endif
