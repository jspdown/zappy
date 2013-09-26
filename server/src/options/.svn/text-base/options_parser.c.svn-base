/*
** options_parser.c for options in /home/guiho_r/depot/zappy/server/src/options
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Jun  4 11:04:41 2013 ronan guiho
** Last update Mon Jul  8 10:49:08 2013 ronan guiho
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "options/option.h"

int options_parser_syntax(char *buffer)
{
  printf("%s: %s option -- '%s'\n", BINARY_NAME,
	 (IS_EXTOPTION(buffer) == 1) ? "unrecognized" : "invalid", \
	 (IS_EXTOPTION(buffer) == 1) ? &buffer[2] : &buffer[1]);
  options_howto();
  return (EXIT_FAILURE);
}

int options_parser_option_arg_ref3(t_opt *opt, const t_refoption *ref,
				  char **av, unsigned int *i)
{
  if (ref->isvalue == 3 && av[*i + 1] == NULL)
    {
      printf("%s: option requires an argument -- '%s'\n", BINARY_NAME,
	     (IS_EXTOPTION(av[*i]) == 1) ? &av[*i][2] : &av[*i][1]);
	  return (EXIT_FAILURE);
    }
  else if (ref->isvalue == 3)
    {
      if (!IS_OPTION(av[*i + 1]))
	{
	  while (av[*i + 1] && !IS_OPTION(av[*i + 1]))
	    {
	      char *tmp = opt->value;
	      if ((opt->value = malloc(sizeof(char) *			\
				       (strlen(av[*i + 1]) + strlen(tmp)) + 2)) == NULL)
		return (EXIT_FAILURE);
	      bzero(opt->value, (strlen(av[*i + 1]) + strlen(tmp)) + 2);
	      sprintf(opt->value, "%s %s", tmp, av[*i + 1]);
	      if (tmp)
		free(tmp);
	      ++(*i);
	    }
	}
    }
  return (EXIT_SUCCESS);
}

int options_parser_option(t_opt *opt, char **av,
			  unsigned int *i, unsigned int *pos)
{
  const t_refoption *ref;

  if (IS_OPTION(av[*i]) == 0 && av[*i + 1] == NULL)
    {
      opt[*pos].eopt = OPT_EXT;
      if (strncpy(opt[*pos].value, av[*i], strlen(av[*i])) == NULL)
	return (EXIT_FAILURE);
    }
  else if ((ref = options_exist(av[*i])) != NULL &&
	   options_get(ref->eopt) == NULL)
    {
      if (options_parser_option_arg(&opt[*pos], ref, av, i) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      ++(*pos);
    }
  else
    return (options_parser_syntax(av[*i]));
  return (EXIT_SUCCESS);
}

int options_parser(t_opt *opt, char **av)
{
  unsigned int i;
  unsigned int pos;

  i = 1;
  pos = 0;
  while (av[i])
    {
      if ((options_parser_option(opt, av, &i, &pos)) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      ++i;
    }
  return (EXIT_SUCCESS);
}
