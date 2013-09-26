/*
** timer_state.c for zappy in /home/leprov_a//project/tek2/zappy/zappy/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed Jun 12 12:12:19 2013 alexis leprovost
** Last update Thu Jul  4 22:08:21 2013 alexis leprovost
*/

#include "timer.h"
#include "extend.h"

t_bool	timer_is_running(t_timer* timer)
{
  if (!timer)
    return (FALSE);
  return (timer->__run__);
}

t_bool	timer_is_stopped(t_timer* timer)
{
  if (!timer)
    return (FALSE);
  return (timer->__stop__);
}

t_bool	timer_is_time_out(t_timer* timer, double seconds)
{
  int const	sec = (int)seconds;
  int const	usec = (seconds - (double)sec) * 1000000.0f;
  t_time	t;

  if (!timer)
    return (FALSE);
  if (timer->is_running(timer))
    t = timer->sub(timer->clock(), timer->__begin__);
  else
    t = timer->sub(timer->__end__, timer->__begin__);
  return (t.sec > sec ? TRUE : (t.sec == sec && t.usec > usec ? TRUE : FALSE));
}
