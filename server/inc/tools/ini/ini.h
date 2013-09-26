/*
** ini.h for ini in /home/guiho_r/projet/myftp/modules/serveur/lib/libini/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Apr  8 13:39:41 2013 ronan guiho
** Last update Mon Jun 17 11:35:17 2013 alexis leprovost
*/

#ifndef __INI_H__
# define __INI_H__

# include <string.h>
# include <stdlib.h>

# include "list.h"

# define C_READ 4096
# define M_BUFFER 4096

# define IS_SECTION(x) ((x[0] == '[' && x[strlen(x) - 1] == ']') ? (1) : (0))

typedef struct s_config_sect
{
  char name[128];
  t_list *field;
} t_config_sect;

typedef struct s_config_field
{
  char name[128];
  char value[128];
} t_config_field;

typedef struct s_config
{
  t_list *sec;
} t_config;

char		*ini_match(t_config *config, char *section, char *name);
t_config	*ini_parse(char *name);
char		*ini_line(const int fd, char *s);
void		ini_clear(char *buffer, char *clear);
int		ini_section_add(char *name, t_config *config);
int		ini_section_by_name(void *data, void *value);
int		ini_field_add(t_config *config, char *buffer);
int		ini_field_by_name(void *data, void *value);

#endif
