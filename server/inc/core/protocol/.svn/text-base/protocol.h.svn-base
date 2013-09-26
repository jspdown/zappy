/*
** protocol.h for protocol in /home/antiqe/Documents/zappy/server/inc/core/protocol
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Jul  2 10:33:57 2013 ronan guiho
** Last update Sat Jul 13 13:14:01 2013 alexis leprovost
*/

#ifndef __CORE_PROTOCOL_H__
# define __CORE_PROTOCOL_H__

# include "extend.h"
# include "core.h"
# include "action.h"
# include "player.h"
# include "core/stack/stack.h"
# include "network/message/message.h"
# include "level.h"

# define PROTOCOL_MESSAGE_COUNT 21
# define PROTOCOL_DATA_MAP_STEP 5

# define PROTOCOL_SEP(c)	(c == '\n' || c == ' ' || c == '\t' ||	\
				 c == '\0' ? 1 : 0)

typedef struct s_proto
{
  char*		name;
  size_t	size;
} t_proto;

typedef struct s_broadcast
{
  t_player*	player;
  char*		message;
} t_broadcast;

extern const t_proto g_proto[];

t_action*	protocol_interpret(t_message *msg);
t_action*	protocol_create(t_action_type type, int index, char* body,
				time_t time);
t_bool		protocol_exec(t_core* core, t_action* action);
t_bool		protocol_send(t_core* core, t_action* action, char* body);
t_bool		protocol_stack(t_core* core, t_player* player);
int		protocol_find_team(void* d1, void* d2);
int		protocol_find_egg(void* d1, void* d2);
t_bool		protocol_level(t_core* core, t_player* player);
void		protocol_up(void* d1, void* d2);
t_bool		protocol_move(t_core* core, t_player* player,
			      t_action* action);
t_bool		protocol_left(t_core* core, t_player* player,
			      t_action* action);
t_bool		protocol_right(t_core* core, t_player* player,
			       t_action* action);
t_bool		protocol_take(t_core* core, t_player* player,
			      t_action* action);
t_bool		protocol_drop(t_core* core, t_player* player,
			      t_action* action);
t_bool		protocol_pre_fork(t_core* core, t_player* player,
				  t_action* action);
t_bool		protocol_connect_nbr(t_core* core, t_player* player,
				     t_action* action);
int		protocol_get_player_by_id(void *data, void *cntx);
t_bool		protocol_get_case(char *buffer, unsigned int *pos);
t_bool		protocol_map_size(t_core* core, t_player* player,
				  t_action* action);
t_bool		protocol_data_case(t_core* core, t_player* player,
				   t_action* action);
t_bool		protocol_data_map_chunk(t_core* core, t_player* player,
					t_action* action);
t_bool		protocol_data_map(t_core* core, t_player* player,
				  t_action* action);
t_bool		protocol_get_team(t_core* core, t_player* player,
				  t_action* action);
t_bool		protocol_pos_player(t_core* core, t_player* player,
				    t_action* action);
t_bool		protocol_level_player(t_core* core, t_player* player,
				      t_action* action);
t_bool		protocol_level_player_aux(t_player *player,
					  t_player *to);
t_bool		protocol_data_player_aux(t_player *player,
					 t_player *to);
t_bool		protocol_data_player(t_core* core, t_player* player,
				     t_action* action);
t_bool		protocol_get_time(t_core* core, t_player* player,
				  t_action* action);
t_bool		protocol_set_time(t_core* core, t_player* player,
				  t_action* action);
t_bool		protocol_death(t_core* core, t_player* player,
			       t_action* action);
t_bool		protocol_disconnect(t_core* core, t_player* player,
				    t_action* action);
t_bool		protocol_spec(t_core* core, t_player* player,
			      t_action* action);
t_bool		protocol_incantation(t_core* core, t_player* player,
				     t_action* action);
t_bool		protocol_elevation(t_core* core, t_player* player,
				   t_action* action);
t_bool		protocol_see(t_core* core, t_player* player, t_action* action);
t_bool		protocol_inventory(t_core* core, t_player* player,
				   t_action* action);
t_bool		protocol_sync(t_core* core, t_player* player,
			      t_action* action);
t_bool		protocol_eclosion(t_core* core, t_player* player,
				  t_action* action);
t_bool		protocol_fork(t_core* core, t_player* player,
			      t_action* action);
t_bool		protocol_corrupt(t_core* core, t_player* player,
				 t_action* action);
t_bool		protocol_broadcast(t_core* core, t_player* player,
				   t_action* action);
void		protocol_do_broadcast(void* d1, void* d2);
void		protocol_do_expulse(void* d1, void* d2);
t_bool		protocol_expulse(t_core* core, t_player* player,
				 t_action* action);
t_bool		protocol_win(t_core* core, t_player* player,
			     t_action* action);
void		protocol_newplayer_auth(void *data, void *cntx);
void		protocol_egg_waslaid_auth(void *data, void *cntx);
void		protocol_newplayer_notify(void *data, void *cntx);
void		protocol_egg_newplayer_notify(void *data, void *cntx);
void		protocol_move_graphic_notify(void *data, void *cntx);
void		protocol_ressource_act_notify(void *data, void *cntx);
void		protocol_incantation_notify(void *data, void *cntx);
void		protocol_fork_notify(void *data, void *cntx);
void		protocol_endfork_notify(void *data, void *cntx);
void		protocol_death_notify(void *data, void *cntx);
void		protocol_egg_hatching_notify(void *data, void *cntx);
void		protocol_egg_musty_notify(void *data, void *cntx);
void		protocol_level_player_notify(void *data, void *cntx);
void		protocol_incantation_end_notify(void *data, void *cntx);
void		protocol_endgame_notify(void *data, void *cntx);
void		protocol_data_case_notify(void *data, void *cntx);
void		protocol_broadcast_notify(void *data, void *cntx);
void		protocol_pos_player_notify(void *data, void *cntx);
int		protocol_count_player(void* d1, void* d2);
void		protocol_data_map_notify(void* data);

#endif
