/*
** option.h for option in /home/guiho_r/projet/myirc-2016-guiho_r/modules/serveur/inc/option
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Apr 22 19:00:39 2013 ronan guiho
** Last update Thu Jul 11 16:10:03 2013 alexis leprovost
*/

#ifndef __OPTION_H__
#define __OPTION_H__

#include <unistd.h>
#include <stdio.h>

#include "list.h"

enum e_option
{
  OPT_INIT = -1,
  OPT_HELP = 0,
  OPT_VERBOSE,
  OPT_TEAMNAME,
  OPT_PORT,
  OPT_WIDTH,
  OPT_HEIGHT,
  OPT_TEAMCOUNT,
  OPT_DELAY,
  OPT_FREQ,
  OPT_MAX,
  OPT_COUNT,
  OPT_EXT
};

typedef struct s_refoption
{
  enum e_option eopt;
  char cmd[3];
  char ext_cmd[64];
  char howto[128];
  char isvalue;
} t_refoption;

typedef struct s_opt
{
  enum e_option eopt;
  char *value;
} t_opt;

typedef struct s_opt_c
{
  t_opt opts[OPT_COUNT + 1];
} t_opt_c;

#define BINARY_NAME "server"

#define IS_OPTION(x) ((x[0] == '-' && x[1] != '\0') ? 1 : 0)
#define IS_EXTOPTION(x) ((x[0] == '-' && x[1] == '-') ? 1 : 0)

#define OPT_USAGE "Usage:\n server [options]"

static const t_refoption tab_refopt[] = {
  {OPT_HELP, "-h", "--help", "display usage", 0},
  {OPT_VERBOSE, "-v", "--verbose", "enabled verbose mode", 0},
  {OPT_TEAMNAME, "-n", "--name", "teams name", 3},
  {OPT_PORT, "-p", "--port", "port bind by server", 1},
  {OPT_WIDTH, "-x", "--width", "width of the game world", 1},
  {OPT_HEIGHT, "-y", "--height", "height of the game world", 1},
  {OPT_TEAMCOUNT, "-c", "--count", "client per teams", 1},
  {OPT_DELAY, "-t", "--time", "delay of action execution", 1},
  {OPT_FREQ, "-f", "--frequency", "frequency of each ressource", 1},
  {OPT_MAX, "-m", "--max", "Win condition", 1}
};

void			options_clear();
void			options_howto();
void			options_display(t_opt *opt);
void			options_init();
int			options_parser(t_opt *opt, char **av);
int			options_parser_option_arg(t_opt *opt, const t_refoption *ref,
			      char **av, unsigned int *i);
int			options_parser_option_arg_ref3(t_opt *opt,
						       const t_refoption *ref,
						       char **av, unsigned int *i);
const t_refoption	*options_exist(char *opt);
t_opt			*options_get(enum e_option eopt);

#endif
