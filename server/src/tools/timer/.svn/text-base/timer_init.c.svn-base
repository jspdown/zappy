/*
** timer_init.c for zappy in /home/leprov_a//project/tek2/zappy/zappy/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed Jun 12 11:20:11 2013 alexis leprovost
** Last update Tue Jun 18 18:20:53 2013 alexis leprovost
*/

#include <stdlib.h>

#include "timer.h"
#include "extend.h"

static void	timer_init_method(t_timer* timer)
{
  timer->start = &timer_start;
  timer->stop = &timer_stop;
  timer->reset = &timer_reset;
  timer->is_running = &timer_is_running;
  timer->is_stopped = &timer_is_stopped;
  timer->is_time_out = &timer_is_time_out;
  timer->get_time = &timer_get_time;
  timer->clock = &timer_clock;
  timer->sub = &timer_sub;
}

static void	timer_init_attr(t_timer* timer)
{
  timer->__begin__.sec = 0;
  timer->__begin__.usec = 0;
  timer->__end__.sec = 0;
  timer->__end__.usec = 0;
  timer->__run__ = FALSE;
  timer->__stop__ = FALSE;
}

t_timer*	new_timer(void)
{
  t_timer*	new;

  if ((new = malloc(sizeof(t_timer))) == NULL)
    return (NULL);
  timer_init_attr(new);
  timer_init_method(new);
  return (new);
}

void		delete_timer(t_timer** timer)
{
  if ((*timer) != NULL)
    {
      free(*timer);
      *timer = NULL;
    }
}
