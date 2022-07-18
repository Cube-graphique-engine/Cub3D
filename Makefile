# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mathmart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 14:46:28 by mathmart          #+#    #+#              #
#    Updated: 2022/07/11 13:02:11 by mathismartini    ###   ########.fr        #
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

TARGET		= cub3D
SRCS		= $(shell find ./src -type f -name *.c)
HEADS		= $(shell find ./include -type f -name *.h)
MK_DIR		= Config
OBJS		= $(SRCS:%.c=%.o)
OBJ_DIR 	= Objects
OBJ_PATH	= $(addprefix $(OBJ_DIR)/, $(OBJS))
DEPENDES	= $(OBJ_PATH:%.o=%.d)
CFLAGS		= -Wall -Werror -Wextra -glldb -O3 -Ofast -flto -march=native -ffast-math
LIBFT		= ./lib/libft/libft.a
MLX			= ./lib/minilibx/libmlx.a
BETTER		= ./lib/bettermlx/libbettermlx.a
INCLUDES	= -I ./lib/minilibx -I ./lib/libft -I ./lib/bettermlx/ -I ./Include
INC_LIB		= -L ./lib/minilibx -L ./lib/bettermlx/ -lbettermlx
LIB			= -lmlx $(INC_LIB) $(INC_INC) -L ./lib/libft/ -lft -lm
CONFIG		= $(shell find [0-9a-zA-Z]* -type d -name "Config")

#################################################################################
#									Prerequis									#
#################################################################################
all: $(TARGET)

build: all

$(LIBFT):
	@$(MAKE) -C ./lib/libft/

$(MLX):
	@$(MAKE) -C ./lib/minilibx

$(BETTER):
	@$(MAKE) -C ./lib/bettermlx

#################################################################################
#									Compilation Objects							#
#################################################################################

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	@gcc $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "\033[2K\r$(PURPLE)$<: $(CYAN)loading..$(RESET)"

$(OBJ_DIR):
	@printf "\033[1;32mCreate OBJS_DIR $(CO_DELET)\033[3;32m [√]\033[0m\n"

#################################################################################
#									Compilation C								#
#################################################################################

$(TARGET): $(LIBFT) $(MLX) $(BETTER) $(HEADS) $(OBJ_PATH)
	@gcc $(LIB) -framework OpenGL -framework AppKit $(CFLAGS) $(OBJ_PATH) -o $(TARGET)
	@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUEE): $(ICONOK)Compiled [√]$(RESET)\n"

#################################################################################
#									Clean										#
#################################################################################

clean:
	@$(RM) $(OBJ_PATH)
	@printf "\033[1;31mDelete OBJS $(CO_DELET)$(TARGET)\033[3;32m [√]\033[0m\n"

fclean:
	@$(RM) $(OBJ_PATH)
	@$(RM) $(TARGET)
	@$(RM) -rf $(TARGET).dSYM a.out Objects
	@printf "\033[1;31mDelete $(CO_DELET)$(TARGET)\033[3;32m [√]\033[0m\n"

clean_library:
	@$(RM) -rf ./lib/libft/*.o
	@$(RM) -rf ./lib/minilibx/*.o
	@printf "\033[1;31mDelete Library OBJS $(CO_DELET)$(TARGET)\033[3;32m [√]\033[0m\n"

fclean_library: clean_library
	@$(RM) -rf ./lib/libft/libft.a
	@$(RM) -rf ./lib/minilibx/*.a
	@printf "\033[1;31mDelete Library .a $(CO_DELET)$(TARGET)\033[3;32m [√]\033[0m\n"

clean_all: fclean_library fclean

#################################################################################
#									Norminette									#
#################################################################################

norme:
	@printf "\033[1;36m"
	norminette -R CheckDefine ./includes/
	@printf "\n\033[1;32m"
	norminette -R CheckForbiddenSourceHeader ./src/

#################################################################################
#									Clena & Compilation							#
#################################################################################

re: fclean all

re_all: fclean fclean_library all

.PHONY: re fclean clean all gmk norme

-include $(DEPENDES)
