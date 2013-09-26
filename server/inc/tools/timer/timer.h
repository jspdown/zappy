/*
** timer.h for zappy in /home/leprov_a//project/tek2/zappy/zappy/server
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed Jun 12 11:26:45 2013 alexis leprovost
** Last update Mon Jun 17 11:33:14 2013 alexis leprovost
*/

#ifndef _TIMER_H_
# define _TIMER_H_

# include "extend.h"

typedef struct s_time
{
  int sec;
  int usec;
} t_time;

typedef struct s_timer
{
  t_time	__begin__;
  t_time	__end__;
  t_bool	__run__;
  t_bool	__stop__;
  void		(*start)(struct s_timer*);
  void		(*stop)(struct s_timer*);
  void		(*reset)(struct s_timer*);
  t_bool	(*is_running)(struct s_timer*);
  t_bool	(*is_stopped)(struct s_timer*);
  t_bool	(*is_time_out)(struct s_timer*, double);
  double	(*get_time)(struct s_timer*);
  t_time	(*clock)(void);
  t_time	(*sub)(t_time, t_time);
} t_timer;

t_timer*	new_timer(void);
void		delete_timer(t_timer** timer);

void		timer_start(t_timer* timer);
void		timer_stop(t_timer* timer);
void		timer_reset(t_timer* timer);
t_bool		timer_is_running(t_timer* timer);
t_bool		timer_is_stopped(t_timer* timer);
t_bool		timer_is_time_out(t_timer* timer, double seconds);
double		timer_get_time(t_timer* timer);
t_time		timer_clock();
t_time		timer_sub(t_time t1, t_time t2);

#endif /* _TIMER_H_ */
