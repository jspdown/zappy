/*
** core_delete.c for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Jul  1 19:49:02 2013 alexis leprovost
** Last update Tue Jul  9 13:24:43 2013 alexis leprovost
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <strings.h>
#include <string.h>

#include "logging/logger/logger.h"
#include "core.h"
#include "extend.h"
#include "option.h"
#include "team.h"
#include "player.h"
#include "stack.h"

static void	core_delete_team(void* data)
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

void	core_delete(t_core* core)
{
  if (core)
    {
      if (core->logger)
	delete_logging_logger(core->logger);
      if (core->map && core->map->is_create(core->map))
	delete_map(&core->map);
      if (core->network)
	delete_network(core->network);
      if (core->pool)
	delete_uuid(&core->pool);
      if (core->team)
	delete_list(&core->team, &core_delete_team);
      if (core->graphic)
	delete_list(&core->graphic, NULL);
      if (core->stack)
	delete_stack(&core->stack);
      if (core->egg)
	delete_list(&core->egg, &free);
    }
}
