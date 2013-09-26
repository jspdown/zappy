/*
** ini_field.c for ini_field in /home/guiho_r/projet/myftp/modules/serveur/lib/libini/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Apr  8 14:57:47 2013 ronan guiho
** Last update Wed Jun 12 16:22:45 2013 alexis leprovost
*/

#include <stdio.h>
#include <stdlib.h>

#include "ini.h"

int ini_field_parse(t_config_field *field, char *buffer)
{
  char *str;
  const char delim[2] = {'=', '\0'};

  if ((str = strtok(buffer, delim)) != NULL)
    {
      bzero(field->name, 128);
      strcpy(field->name, str);
      if ((str = strtok(NULL, delim)) != NULL)
	{
	  bzero(field->value, 128);
	  strcpy(field->value, str);
	}
      else
	return (EXIT_FAILURE);
    }
  else
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int ini_field_by_name(void *data, void *value)
{
  char *name;
  t_config_field *field;

  name = (char *)value;
  field = (t_config_field *)data;
  if (strcmp(name, field->name) == 0)
    return (1);
  return (0);
}

int ini_field_add(t_config *config, char *buffer)
{
  t_config_sect *sect;
  t_config_field *field;

  if (config->sec->size(config->sec) > 0)
    {
      if ((sect = (t_config_sect *)config->sec->back(config->sec)))
	{
	  if ((field = malloc(sizeof(t_config_field))) == NULL)
	    return (EXIT_FAILURE);
	  if (ini_field_parse(field, buffer) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	  sect->field->push_back(sect->field, field);
	}
    }
  return (EXIT_SUCCESS);
}
