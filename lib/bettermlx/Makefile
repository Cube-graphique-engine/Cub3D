# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 21:08:39 by mathismartini     #+#    #+#              #
#    Updated: 2022/08/24 15:07:35 by mathismartini    ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libbettermlx.a

SRCS		= bettermlx_clean_display.c bettermlx_destroy_image.c \
				bettermlx_destroy_window.c bettermlx_draw_line.c \
				bettermlx_get_color.c bettermlx_get_memory_position.c \
				bettermlx_hook.c bettermlx_init_image.c bettermlx_init_window.c \
				bettermlx_init_xpm_image.c bettermlx_pixel_put.c bettermlx_put_image.c \
				bettermlx_register_loop.c bettermlx_render.c bettermlx_set_color.c

HEADS		= bettermlx.h bettermlx_func.h bettermlx_struct.h

OBJS		= $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADS)
	@ar -r $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@$(RM) $(OBJS)

fclean:
	@$(RM) $(OBJS)
	@$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all