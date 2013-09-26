/*
** core_team.c for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue Jul  2 14:39:44 2013 alexis leprovost
** Last update Sat Jul 13 10:39:35 2013 alexis leprovost
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "core.h"
#include "extend.h"

static t_list*		core_team(int size, char* name)
{
  t_list*	list;
  t_team*	team;
  char*		tmp;

  if (!(tmp = strtok(name, " ")) || !(list = new_list()) || size <= 0)
    return (NULL);
  while (size && tmp)
    {
      if ((team = malloc(sizeof(t_team))))
	{
	  team->name = strndup(tmp, MAX_TEAM_NAME);
	  team->size = size;
	  team->max = 0;
	  list->push_front(list, team);
	  tmp = strtok(NULL, " ");
	}
      size = !team || !team->name ? 0 : size;
    }
  if (!size && list->size(list) < 2)
    delete_list(&list, NULL);
  return (list);
}

static int		core_team_cmp(void* d1, void* d2)
{
  return (!strcmp(((t_team*)d1)->name, ((t_team*)d2)->name));
}

static void		core_team_free(void* data)
{
  t_team*	team;

  team = (t_team*)data;
  if (team)
    {
      if (team->name)
	free(team->name);
      free(team);
    }
}

t_bool	core_init_team(t_core* core)
{
  t_log_message	msg;
  t_opt*	size;
  t_opt*	name;
  t_bool	ret;

  size = options_get(OPT_TEAMCOUNT);
  name = options_get(OPT_TEAMNAME);
  core->team = core_team(size ? atoi(size->value) : DEFAULT_TEAMSIZE,
			 name ? name->value : NULL);
  ret = FALSE;
  if (!core->team)
    init_logging_message(&msg, "Core", "Team initialization failed", ERROR);
  else if (core->team->size(core->team) < NB_TEAM_MIN)
    init_logging_message(&msg, "Core", "Not enough team", ERROR);
  else if (!core->team->uniq(core->team, &core_team_cmp, &core_team_free))
    init_logging_message(&msg, "Core", "Same team name", ERROR);
  else
    {
      init_logging_message(&msg, "Core", "Initializing of Team...", NOTICE);
      ret = TRUE;
    }
  if (core->logger)
    core_logging(core->logger, &msg);
  return (ret);
}
