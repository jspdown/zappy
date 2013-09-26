/*
** core_generate.c for zappy in /home/leprov_a//project/tek2/zappy/dev/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed Jun 19 15:41:54 2013 alexis leprovost
** Last update Sat Jul  6 15:35:23 2013 alexis leprovost
*/

#include <stdlib.h>

#include "core.h"
#include "extend.h"
#include "option.h"
#include "network.h"
#include "team.h"

t_bool	core_generate_world(t_core* core)
{
  t_log_message msg;
  t_opt*	w;
  t_opt*        h;
  t_bool        ret;

  if (!core)
    return (FALSE);
  w = options_get(OPT_WIDTH);
  h = options_get(OPT_HEIGHT);
  ret = core->map->create(core->map, (w ? atoi(w->value) : DEFAULT_WIDTH),
			  (h ? atoi(h->value) : DEFAULT_HEIGHT));
  w = options_get(OPT_FREQ);
  ret = (core->map->generate(core->map, w ? atof(w->value) :	\
			     DEFAULT_FREQUENCY) & ret);
  if (!ret)
    init_logging_message(&msg, "Core", "Cannot generate world", FATAL);
  else
    init_logging_message(&msg, "Core", "World generation...", NOTICE);
  if (core->state)
    core_logging(core->logger, &msg);
  return (core->state ? ret : FALSE);
}

t_bool	core_generate_id(t_core* core)
{
  t_log_message	msg;
  size_t	nb;
  t_bool	ret;

  if (!core)
    return (FALSE);
  nb = ((t_team*)core->team->front(core->team))->max;
  nb = nb < 6 ? 6 : nb;
  nb = core->team->size(core->team) * nb;
  if ((ret = core->pool->create(core->pool, nb)))
    init_logging_message(&msg, "Core", "Id generation...", NOTICE);
  else
    init_logging_message(&msg, "Core", "Cannot generate id", FATAL);
  if (core->state)
    core_logging(core->logger, &msg);
  return (core->state ? ret : FALSE);
}
