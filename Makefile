# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mathmart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 14:46:28 by mathmart          #+#    #+#              #
#    Updated: 2022/08/22 18:01:32 by mathmart         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#################################################################################
#									Colors										#
#################################################################################

GREY		= \033[4;34m
RED			= \033[1;31m
GREEN		= \033[3;32m
YELLOW		= \033[2;49;33m
BLUE		= \033[4;34m
BLUEE		= \033[3;34m
PURPLE		= \033[3;35m
CYAN		= \033[3;36m
RESET		= \033[0m
ICONOK		= \033[1;32m
ICONKO		= \033[1;31m
CO_DELET	= \033[4;31m
CO_A_OUT	= \033[96m
WHITE		= \033[1;49;97m

#################################################################################
#									Variables									#
#################################################################################

NAME		= cub3D
SRCS		= $(shell find ./src -type f -name *.c)
HEADS		= $(shell find ./include -type f -name *.h)
HEADS		+=$(shell find ./lib/libft -type f -name *.h)
HEADS		+=$(shell find ./lib/minilibx -type f -name *.h)
HEADS		+=$(shell find ./lib/bettermlx/ -type f -name *.h)
HEADS		+= ./lib/libft/libft.a ./lib/minilibx/libmlx.a ./lib/bettermlx/libbettermlx.a
OBJS		= $(SRCS:%.c=%.o)
OBJ_DIR 	= Objects
OBJ_PATH	= $(addprefix $(OBJ_DIR)/, $(OBJS))
CFLAGS		= -Wall -Werror -Wextra -glldb -O3 -Ofast -flto -march=native -ffast-math -pipe #-fsanitize=address -g3
INCLUDES	= -I ./lib/minilibx -I ./lib/libft -I ./lib/bettermlx/ -I ./Include
INC_LIB		= -L ./lib/minilibx -L ./lib/bettermlx/ -lbettermlx
LIB			= -lmlx $(INC_LIB) -L ./lib/libft/ -lft -lm

#################################################################################
#									Prerequis									#
#################################################################################

all: libraries $(NAME)

libraries:
	@$(MAKE) -C ./lib/libft
	@$(MAKE) -C ./lib/minilibx
	@$(MAKE) -C ./lib/bettermlx

build: all

#################################################################################
#									Compilation Objects							#
#################################################################################

$(OBJ_DIR)/%.o: %.c $(HEADS)| $(OBJ_DIR)
	@mkdir -p $(@D)
	@gcc $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "\033[2K\r$(PURPLE)$<: $(CYAN)loading..$(RESET)"

$(OBJ_DIR):
	@printf "\033[1;32mCreate OBJS_DIR $(CO_DELET)\033[3;32m [√]\033[0m\n"

#################################################################################
#									Compilation C								#
#################################################################################

$(NAME): $(OBJ_PATH)
	@gcc $(LIB) -framework OpenGL -framework AppKit $(CFLAGS) $(OBJ_PATH) -o $(NAME)
	@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUEE): $(ICONOK)Compiled [√]$(RESET)\n"

#################################################################################
#									Clean										#
#################################################################################

clean:
	@$(RM) $(OBJ_PATH)
	@printf "\033[1;31mDelete OBJS $(CO_DELET)$(NAME)\033[3;32m [√]\033[0m\n"

fclean:
	@$(RM) $(OBJ_PATH)
	@$(RM) $(NAME)
	@$(RM) -rf $(NAME).dSYM a.out Objects
	@printf "\033[1;31mDelete $(CO_DELET)$(NAME)\033[3;32m [√]\033[0m\n"

clean_library:
	@$(MAKE) -C ./lib/libft clean
	@$(MAKE) -C ./lib/minilibx clean
	@$(MAKE) -C ./lib/bettermlx clean
	@printf "\033[1;31mDelete Library OBJS $(CO_DELET)$(NAME)\033[3;32m [√]\033[0m\n"

fclean_library: clean_library
	@$(MAKE) -C ./lib/libft fclean
	@$(MAKE) -C ./lib/bettermlx fclean
	@printf "\033[1;31mDelete Library .a $(CO_DELET)$(NAME)\033[3;32m [√]\033[0m\n"

clean_all: fclean_library fclean

#################################################################################
#									Norminette									#
#################################################################################

norme:
	@printf "\033[1;36m"
	norminette -R CheckDefine ./include/
	@printf "\n\033[1;32m"
	norminette -R CheckForbiddenSourceHeader ./src/

#################################################################################
#									Clena & Compilation							#
#################################################################################

re: fclean
	$(MAKE) all

re_all: fclean fclean_library all

.PHONY: re fclean clean all gmk norme
