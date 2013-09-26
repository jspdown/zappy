/*
** ini_init.c for ini in /home/guiho_r/projet/myftp/modules/serveur/lib/libini/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Apr  8 13:36:59 2013 ronan guiho
** Last update Wed Jun 12 16:13:30 2013 alexis leprovost
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "ini.h"

int ini_parse_file(t_config *config, FILE *file)
{
  char buffer[C_READ];
  char cbuffer[C_READ];
  unsigned int i;

  i = 0;
  (void)config;
  while (ini_line(fileno(file), buffer))
    {
      ini_clear(buffer, cbuffer);
      if (strlen(cbuffer) > 1)
	{
	  if (IS_SECTION(cbuffer))
	    ini_section_add(cbuffer, config);
	  else
	    if (ini_field_add(config, cbuffer) == EXIT_FAILURE)
	      printf("libini: Error: Syntax error at line %d\n", i);
	}
    }
  return (EXIT_SUCCESS);
}
t_config *ini_parse(char *name)
{
  FILE *file;
  t_config *config;

  if ((file = fopen(name, "r")) == NULL)
    {
      printf("Libini: Error: Cannot open configuration file.\n");
      return (NULL);
    }
  if ((config = malloc(sizeof(t_config))) == NULL)
    return (NULL);
  config->sec = new_list();
  ini_parse_file(config, file);
  fclose(file);
  return (config);
}

void ini_free(t_config *config)
{
  config->sec->clear(config->sec, 0);
  free(config);
}
