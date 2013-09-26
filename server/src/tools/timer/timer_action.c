/*
** timer_action.c for zappy in /home/leprov_a//project/tek2/zappy/zappy/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed Jun 12 11:52:55 2013 alexis leprovost
** Last update Wed Jun 12 15:29:53 2013 alexis leprovost
*/

#include "timer.h"
#include "extend.h"

void	timer_start(t_timer* timer)
{
  t_time	t;

  if (timer && !timer->is_running(timer))
    {
      if (timer->is_stopped(timer))
	{
	  t = timer->sub(timer->__end__, timer->__begin__);
	  timer->__begin__ = timer->sub(timer->clock(), t);
	  timer->__stop__ = FALSE;
	}
      else
	timer->__begin__ = timer->clock();
      timer->__run__ = TRUE;
    }
}

void	timer_stop(t_timer* timer)
{
  if (timer && timer->is_running(timer))
    {
      timer->__stop__ = TRUE;
      timer->__run__ = FALSE;
      timer->__end__ = timer->clock();
    }
}

void	timer_reset(t_timer* timer)
{
  if (timer)
    {
      timer->__begin__.sec = 0;
      timer->__begin__.usec = 0;
      timer->__end__.sec = 0;
      timer->__end__.usec = 0;
      timer->__run__ = FALSE;
      timer->__stop__ = FALSE;
    }
}
