##
## Makefile for server in /home/guiho_r/depot/zappy/server
## 
## Made by ronan guiho
## Login   <guiho_r@epitech.net>
## 
## Started on  Fri May 31 20:57:06 2013 ronan guiho
##

NAME		=	server

SRC_DIR		=	src/
INC_DIR		=	inc/

SRC		=	$(SRC_DIR)main.c

SRC		+=	$(SRC_DIR)tools/timer/timer_init.c \
			$(SRC_DIR)tools/timer/timer_action.c \
			$(SRC_DIR)tools/timer/timer_state.c \
			$(SRC_DIR)tools/timer/timer_util.c \

SRC		+=	$(SRC_DIR)tools/uuid/uuid_init.c \
			$(SRC_DIR)tools/uuid/uuid_access.c \
			$(SRC_DIR)tools/uuid/uuid_util.c \
			$(SRC_DIR)tools/uuid/uuid_create.c \

SRC		+=	$(SRC_DIR)tools/list/list_init.c \
			$(SRC_DIR)tools/list/list_add.c \
			$(SRC_DIR)tools/list/list_sub.c \
			$(SRC_DIR)tools/list/list_access.c \
			$(SRC_DIR)tools/list/list_algorithm.c \
			$(SRC_DIR)tools/list/list_util.c \
			$(SRC_DIR)tools/list/list_tool.c \
			$(SRC_DIR)tools/list/list_advanced_algorithm.c \
			$(SRC_DIR)tools/list/list_insert.c \

SRC		+=	$(SRC_DIR)tools/ini/ini_init.c \
			$(SRC_DIR)tools/ini/ini_line.c \
			$(SRC_DIR)tools/ini/ini_clear.c \
			$(SRC_DIR)tools/ini/ini_section.c \
			$(SRC_DIR)tools/ini/ini_field.c \

SRC		+=	$(SRC_DIR)core/core.c \
			$(SRC_DIR)core/core_options.c \
			$(SRC_DIR)core/core_init.c \
			$(SRC_DIR)core/core_delete.c \
			$(SRC_DIR)core/core_generate.c \
			$(SRC_DIR)core/core_logging.c \
			$(SRC_DIR)core/core_state.c \
			$(SRC_DIR)core/core_time.c \
			$(SRC_DIR)core/core_table.c \
			$(SRC_DIR)core/core_map.c \
			$(SRC_DIR)core/core_network.c \
			$(SRC_DIR)core/core_team.c \
			$(SRC_DIR)core/core_pool.c \
			$(SRC_DIR)core/core_graphic.c \
			$(SRC_DIR)core/core_stack.c \
			$(SRC_DIR)core/core_exec.c \
			$(SRC_DIR)core/core_egg.c \

SRC		+=	$(SRC_DIR)core/player/player_allocate.c \
			$(SRC_DIR)core/player/player_view.c \
			$(SRC_DIR)core/player/player_view_aux.c

SRC		+=	$(SRC_DIR)core/map/map_init.c \
			$(SRC_DIR)core/map/map_util.c \
			$(SRC_DIR)core/map/map_generate.c \

SRC		+=	$(SRC_DIR)core/stack/stack_init.c \
			$(SRC_DIR)core/stack/stack_util.c \
			$(SRC_DIR)core/stack/stack_tool.c \

SRC		+=	$(SRC_DIR)core/protocol/protocol_behaviour.c \
			$(SRC_DIR)core/protocol/protocol_move.c \
			$(SRC_DIR)core/protocol/protocol_handle.c \
			$(SRC_DIR)core/protocol/protocol_send.c \
			$(SRC_DIR)core/protocol/protocol_sync.c \
			$(SRC_DIR)core/protocol/protocol_logic.c \
			$(SRC_DIR)core/protocol/protocol_info.c \
			$(SRC_DIR)core/protocol/protocol_physic.c \
			$(SRC_DIR)core/protocol/protocol_util.c \
			$(SRC_DIR)core/protocol/protocol_tool.c \
			$(SRC_DIR)core/protocol/protocol_map_size.c \
			$(SRC_DIR)core/protocol/protocol_data_case.c \
			$(SRC_DIR)core/protocol/protocol_data_map.c \
			$(SRC_DIR)core/protocol/protocol_get_team.c \
			$(SRC_DIR)core/protocol/protocol_pos_player.c \
			$(SRC_DIR)core/protocol/protocol_level_player.c \
			$(SRC_DIR)core/protocol/protocol_data_player.c \
			$(SRC_DIR)core/protocol/protocol_get_time.c \
			$(SRC_DIR)core/protocol/protocol_set_time.c \
			$(SRC_DIR)core/protocol/protocol_new_player.c \
			$(SRC_DIR)core/protocol/protocol_egg_waslaid.c \
			$(SRC_DIR)core/protocol/protocol_egg_newplayer.c \
			$(SRC_DIR)core/protocol/protocol_move_graphic.c \
			$(SRC_DIR)core/protocol/protocol_ressource.c \
			$(SRC_DIR)core/protocol/protocol_broadcast.c \
			$(SRC_DIR)core/protocol/protocol_incantation.c \
			$(SRC_DIR)core/protocol/protocol_incantation_end.c \
			$(SRC_DIR)core/protocol/protocol_fork.c \
			$(SRC_DIR)core/protocol/protocol_death.c \
			$(SRC_DIR)core/protocol/protocol_egg.c \
			$(SRC_DIR)core/protocol/protocol_endgame.c \
			$(SRC_DIR)core/protocol/protocol_do.c \
			$(SRC_DIR)core/protocol/protocol_expulse.c

SRC		+=	$(SRC_DIR)options/options.c \
			$(SRC_DIR)options/options_parser.c \
			$(SRC_DIR)options/options_parser_arg.c \
			$(SRC_DIR)options/options_utils.c \

SRC		+=	$(SRC_DIR)logging/message/message_allocate.c \
			$(SRC_DIR)logging/channel/channel_console_allocate.c \
			$(SRC_DIR)logging/channel/channel_console_behavior.c \
			$(SRC_DIR)logging/channel/channel_file_allocate.c \
			$(SRC_DIR)logging/channel/channel_file_behavior.c \
			$(SRC_DIR)logging/logger/logger_allocate.c \
			$(SRC_DIR)logging/logger/logger_channel.c \
			$(SRC_DIR)logging/logger/logger_behavior.c \

SRC		+=	$(SRC_DIR)network/client/client_allocate.c \
			$(SRC_DIR)network/client/client_behaviour.c \
			$(SRC_DIR)network/client/client_exchange.c \
			$(SRC_DIR)network/client/client_getter.c \
			$(SRC_DIR)network/server/server_allocate.c \
			$(SRC_DIR)network/server/server_behaviour.c \

SRC		+=	$(SRC_DIR)network/network_init.c \
			$(SRC_DIR)network/network_init_sub.c \
			$(SRC_DIR)network/network_log.c \
			$(SRC_DIR)network/network_allocate.c \
			$(SRC_DIR)network/network_multiplexer.c \
			$(SRC_DIR)network/network_multiplexer_fdset.c \
			$(SRC_DIR)network/network_multiplexer_client.c \
			$(SRC_DIR)network/network_multiplexer_acceptclient.c \
			$(SRC_DIR)network/network_multiplexer_disconnect.c \
			$(SRC_DIR)network/network_multiplexer_sendqueue.c \

SRC		+=	$(SRC_DIR)network/message/message_allocate.c \

SRC		+=	$(SRC_DIR)network/aggregator/aggregator_allocate.c \
			$(SRC_DIR)network/aggregator/aggregator_behaviour.c \
			$(SRC_DIR)network/aggregator/aggregator_integrity.c \
			$(SRC_DIR)network/aggregator/aggregator_integrity_aux.c \

OBJ		=	$(SRC:.c=.o)

TMP		=	$(SRC:.c=.c~)

LDFLAGS		=

CFLAGS		=	-Wall -Wextra -W -O3 -Wno-unused-result

CFLAGS		+=	-I $(INC_DIR) \
			-I $(INC_DIR)tools/ini \
			-I $(INC_DIR)tools/list \
			-I $(INC_DIR)tools/timer \
			-I $(INC_DIR)tools/uuid \
			-I $(INC_DIR)core \
			-I $(INC_DIR)core/player \
			-I $(INC_DIR)core/ressource \
			-I $(INC_DIR)core/map \
			-I $(INC_DIR)core/stack \
			-I $(INC_DIR)core/protocol \
			-I $(INC_DIR)network \
			-I $(INC_DIR)options \

CC		=	gcc

DEL_FILE	=	rm -f

ifeq ($(DEBUG), YES)
	CFLAGS 	+=	-g
	DEBUGFLAGS = \033[1;31m DEBUG\033[0m
endif

ifeq ($(PROFIL), YES)
	CFLAGS 	+=	-pg
	PROFILFLAGS = \033[1;31m PROFIL\033[0m
endif

all:			$(NAME)

$(NAME):		$(OBJ)
			@$(CC) -o $@ $^ $(LDFLAGS)
			@printf "\r[\033[1;33mLINK\033[0m] $@\n"

%.o:			%.c
			@$(CC) -o $@ -c $< $(CFLAGS)
			@printf "\r[\033[1;32mBUILD\033[0m$(DEBUGFLAGS)$(PROFILFLAGS)] $<\n"

clean:
			@$(DEL_FILE) $(OBJ)
			@$(DEL_FILE) $(TMP)
			@printf "\r[\033[1;31mDELETE\033[0m] *.o *~\n"

fclean:			clean
			@$(DEL_FILE) $(NAME)
			@printf "\r[\033[1;31mDELETE\033[0m] $(NAME)\n"

re:			fclean all

.PHONY:			all clean fclean re
