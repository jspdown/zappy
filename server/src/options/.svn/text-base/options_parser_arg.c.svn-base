/*
** options_parser.c for options in /home/guiho_r/depot/zappy/server/src/options
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Jun  4 11:04:41 2013 ronan guiho
** Last update Mon Jul  8 10:49:52 2013 ronan guiho
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "options/option.h"

int options_parser_option_arg_aux(t_opt *opt, const t_refoption *ref,
				  char **av, unsigned int *i)
{
  if (ref->isvalue == 1)
    {
      if (strncpy(opt->value, av[*i + 1], strlen(av[*i + 1])) == NULL)
	return (EXIT_FAILURE);
      if (av[*i + 1] != NULL)
	++(*i);
    }
  else if (ref->isvalue == 2 && av[*i + 1] != NULL)
    {
      if (!IS_OPTION(av[*i + 1]))
	{
	  if (strncpy(opt->value, av[*i + 1], strlen(av[*i + 1])) == NULL)
	    return (EXIT_FAILURE);
	}
      if (av[*i + 1] != NULL)
	++(*i);
    }
  return (EXIT_SUCCESS);
}

int options_parser_option_arg(t_opt *opt, const t_refoption *ref,
			      char **av, unsigned int *i)
{
  opt->eopt = ref->eopt;
  if (ref->isvalue == 3)
    {
      if ((options_parser_option_arg_ref3(opt, ref, av, i)) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  else if (ref->isvalue == 1 && av[*i + 1] == NULL)
    {
      printf("%s: option requires an argument -- '%s'\n", BINARY_NAME,
	     (IS_EXTOPTION(av[*i]) == 1) ? &av[*i][2] : &av[*i][1]);
	  return (EXIT_FAILURE);
    }
  else
    if ((options_parser_option_arg_aux(opt, ref, av, i)) == EXIT_FAILURE)
      return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

