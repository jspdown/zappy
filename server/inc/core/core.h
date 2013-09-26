/*
** core.h for core in /home/guiho_r/depot/zappy/server/src/core
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Jun  4 11:15:43 2013 ronan guiho
** Last update Fri Jul 12 16:32:30 2013 alexis leprovost
*/

#ifndef __CORE_H__
# define __CORE_H__

# include <sys/types.h>
# include <unistd.h>
# include <sys/time.h>

# include "logging/logger/logger.h"
# include "network.h"
# include "map.h"
# include "uuid.h"
# include "extend.h"
# include "list.h"
# include "stack.h"
# include "option.h"

# define CORE_LOGGER_NAME		"core"
# define CORE_CHANNEL_CONSOLE_NAME	"core_console"
# define CORE_CHANNEL_FILE_NAME		"core_logfile"
# define CORE_LOG_NAME			"log_core"

# define DEFAULT_PORT			8484
# define DEFAULT_WIDTH			20
# define DEFAULT_HEIGHT			20
# define DEFAULT_TEAMSIZE		1
# define DEFAULT_TIME			100.0f
# define DEFAULT_FREQUENCY		50.0f
# define DEFAULT_MAX			6

# define ACTION_MAX			10
# define ERROR_MAX			42
# define NB_TEAM_MIN			2
# define MAX_TEAM_NAME			126

typedef struct s_core
{
  t_bool	state;
  double	time;
  size_t	max;
  t_logger*	logger;
  t_map*	map;
  t_network*	network;
  t_uuid*	pool;
  t_list*	team;
  t_list*	graphic;
  t_stack*	stack;
  t_list*	egg;
} t_core;

int	core_init(t_core* core);
t_bool	core_init_logger(t_core* core);
t_bool	core_init_state(t_core* core, t_opt* opt);
t_bool	core_init_time(t_core* core, t_opt* opt);
t_bool	core_init_map(t_core* core);
t_bool	core_init_network(t_core* core, t_opt* opt);
t_bool	core_init_pool(t_core* core);
t_bool	core_init_team(t_core* core);
t_bool	core_init_graphic(t_core* core);
t_bool	core_init_stack(t_core* core);
t_bool	core_init_table_time(double time);
t_bool	core_init_egg(t_core* core);
void	core_init_table_part();

int	core_run(char **av);
int	core_options(char **argv);
void	core_logging(t_logger *log, t_log_message *msg);
void	core_delete(t_core* core);
void	core_interruption(int seg);
t_bool	core_generate_world(t_core* core);
t_bool	core_generate_id(t_core* core);
t_bool	core_exec(t_core* core);
void	core_maj_time(t_core* core, struct timeval* time_out);

#endif
