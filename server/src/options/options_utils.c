/*
** options_utils.c for options in /home/guiho_r/depot/zappy/server/src/options
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Jun  4 11:04:55 2013 ronan guiho
** Last update Tue Jun  4 11:06:01 2013 ronan guiho
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "options/option.h"

t_opt_c *g_opt;

const t_refoption *options_exist(char *opt)
{
  unsigned int i;

  i = 0;
  while (i < OPT_COUNT)
    {
      if ((strcmp(opt, tab_refopt[i].cmd) == 0) ||
	  (strcmp(opt, tab_refopt[i].ext_cmd) == 0))
	return (&tab_refopt[i]);
      ++i;
    }
  return (NULL);
}

t_opt *options_get(enum e_option eopt)
{
  unsigned int i;

  i = 0;
  while (i < OPT_COUNT)
    {
      if (g_opt->opts[i].eopt == eopt)
	  return (&g_opt->opts[i]);
      ++i;
    }
  return (NULL);
}
