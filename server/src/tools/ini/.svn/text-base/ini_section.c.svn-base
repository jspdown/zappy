/*
** ini_section.c for ini_section in /home/guiho_r/projet/myftp/modules/serveur/lib/libini/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Apr  8 14:42:16 2013 ronan guiho
** Last update Wed Jun 12 16:20:19 2013 alexis leprovost
*/

#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "ini.h"

int ini_section_add(char *name, t_config *config)
{
  t_config_sect *sec;

  if ((sec = malloc(sizeof(t_config_sect))) == NULL)
    return (EXIT_FAILURE);
  sec->field = new_list();
  bzero(sec->name, 128);
  strcpy(sec->name, &name[1]);
  if (strlen(name) >= 3)
    sec->name[strlen(name) - 2] = '\0';
  config->sec->push_back(config->sec, sec);
  return (EXIT_SUCCESS);
}

int ini_section_by_name(void *data, void *value)
{
  char *name;
  t_config_sect *sec;

  name = (char *)value;
  sec = (t_config_sect *)data;
  if (strcmp(sec->name, name) == 0)
    return (1);
  return (0);
}

char *ini_match(t_config *config, char *nsect, char *name)
{
  t_config_sect *sect;
  t_config_field *field;

  if (config)
    {
      sect = config->sec->find_if(config->sec, nsect, &ini_section_by_name);
      if (sect != NULL)
	{
	  field = sect->field->find_if(sect->field, name, &ini_field_by_name);
	  if (field != NULL)
	    return (field->value);
	}
    }
  return (NULL);
}
