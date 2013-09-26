/*
** timer_util.c for zappy in /home/leprov_a//project/tek2/zappy/zappy/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed Jun 12 12:46:59 2013 alexis leprovost
** Last update Thu Jul  4 17:48:19 2013 alexis leprovost
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#include "timer.h"
#include "extend.h"

double	timer_get_time(t_timer* timer)
{
  t_time t;

  if (!timer || !timer->__run__)
    return (0.0f);
  if (timer->is_stopped(timer))
    t = timer->sub(timer->__end__, timer->__begin__);
  else
    t = timer->sub(timer->clock(), timer->__begin__);
  return ((double)t.sec + (((double)t.usec) / 1000000));
}

t_time	timer_clock()
{
  struct timeval tv;
  t_time	 t;

  gettimeofday(&tv, NULL);
  t.sec = tv.tv_sec;
  t.usec = tv.tv_usec;
  return (t);
}

t_time	timer_sub(t_time t1, t_time t2)
{
  t_time t;

  t.sec = ABS(t1.sec - t2.sec);
  t.usec = t1.usec - t2.usec;

  if (t.usec < 0)
    {
      --t.sec;
      t.usec = 1000000 + t.usec;
    }
  return (t);
}
