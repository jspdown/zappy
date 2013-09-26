/*
** options.c for options in /home/guiho_r/depot/zappy/server/src/options
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Jun  4 11:04:27 2013 ronan guiho
** Last update Tue Jun 18 10:59:18 2013 alexis leprovost
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "options/option.h"

t_opt_c *g_opt;

void options_init()
{
  unsigned int i;

  i = 0;
  while (i < OPT_COUNT)
    {
      g_opt->opts[i].eopt = OPT_INIT;
      if ((g_opt->opts[i].value = malloc(sizeof(char) * 256)) != NULL)
	bzero(g_opt->opts[i].value, 256);
      ++i;
    }
}

void options_howto()
{
  unsigned int i;

  i = 0;
  printf("%s\n\n", OPT_USAGE);
  printf("Options:\n");
  while (i < OPT_COUNT)
    {
      printf(" %s, %s\t\t%s\n", tab_refopt[i].cmd, tab_refopt[i].ext_cmd, \
	     tab_refopt[i].howto);
      ++i;
    }
  printf("\n");
}

void options_clear()
{
  unsigned int i;

  i = 0;
  while (i < OPT_COUNT)
    {
      free(g_opt->opts[i].value);
      ++i;
    }
  free(g_opt);
}
