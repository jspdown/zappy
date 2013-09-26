/*
** core_options.c for core_options in /home/guiho_r/depot/zappy/server/src/core
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Jun  4 11:08:02 2013 ronan guiho
** Last update Tue Jun 18 10:55:33 2013 alexis leprovost
*/

#include <stdlib.h>

#include "options/option.h"

t_opt_c *g_opt;

int core_options(char **argv)
{
  if ((g_opt = malloc(sizeof(t_opt_c))) == NULL)
    return (EXIT_FAILURE);
  options_init();
  if ((options_parser(g_opt->opts, argv)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (options_get(OPT_HELP))
    {
      options_howto();
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
