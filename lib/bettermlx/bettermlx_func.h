/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_func.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:42:09 by mathmart          #+#    #+#             */
/*   Updated: 2022/08/24 15:07:35 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BETTERMLX_FUNC_H
# define BETTERMLX_FUNC_H

/*
**	START CUSTOM INCLUDES
*/
# include "bettermlx_struct.h"
# include "bettermlx.h"
/*
**	END CUSTOM INCLUDES
*/

/*
**	Initialize window. (allocated)
**	./bettermlx/window/bettermlx_init_window.c
*/
t_window		*bettermlx_init_window(char *title, \
	int width, \
	int height, \
	int divider);

/*
**	Destroy(free) window. (allocated)
**	./bettermlx/window/bettermlx_destroy_window.c
*/
void			*bettermlx_destroy_window(t_window **window);

/*
**	Initialize image in window window. (allocated)
**	./bettermlx/window/bettermlx_init_image.c
*/
t_image			*bettermlx_init_image(t_window *window, \
	int width, \
	int height);

/*
**	Initialize image in window window from xpm file
**	located at relative path char* path. (allocated)
**	./bettermlx/window/bettermlx_init_xpm_image.c
*/
t_image			*bettermlx_init_xpm_image(t_window *window, \
	char *path);

/*
**	Destroy(free) image. (allocated)
**	./bettermlx/window/bettermlx_destroy_image.c
*/
void			*bettermlx_destroy_image(t_window *window, \
	t_image **image);

/*
**	Get the position in memory of pixel (x,y) in t_image *image.
**	./bettermlx/display/bettermlx_get_memory_position.c
*/
unsigned char	*bettermlx_get_memory_position(t_image *image, \
	int x, \
	int y);

/*
**	Get the color of pixel (x,y) in t_image *image.
**	./bettermlx/display/bettermlx_get_color.c
*/
t_color			bettermlx_get_color(t_image *image, \
	int x, \
	int y);

/*
**	Set the color of pixel (x,y) in t_image *image.
**	./bettermlx/display/bettermlx_set_color.c
*/
void			bettermlx_set_color(t_image *image, \
	t_vector3 pixel_coordinates, \
	t_color color, \
	float darkness);

/*
**	Put pixel of t_color color at (x,y) in window window.
**	./bettermlx/display/bettermlx_pixel_put.c
*/
void			bettermlx_pixel_put(t_window *window, \
			t_vector3 pixel_coordinates, \
			t_color color, \
			float darkness);

/*
**	Put image in window window.
**	./bettermlx/display/bettermlx_put_image.c
*/
void			bettermlx_put_image(t_window *window, \
			t_image *image, \
			int x, \
			int y);

/*
**	Draw a line
**	./bettermlx/display/bettermlx_draw_line.c
*/
void			bettermlx_draw_line(t_window *window, \
			t_vector3 xy1, \
			t_vector3 xy2, \
			t_color color);

/*
**	Set all pixels to black.
**	./bettermlx/display/clean_display.c
*/
void			bettermlx_clean_display(t_window *window);

/*
**	Render window.
**	./bettermlx/display/render.c
*/
void			bettermlx_render(t_window *window);

/*
**	Register new hook.
**	./bettermlx/hook/bettermlx_hook.c
*/
void			bettermlx_hook(t_window *window, \
			t_x11event x11event, \
			int (*funct)(), \
			void *param);

/*
**	Register loop hook.
**	./bettermlx/hook/bettermlx_register_loop.c
*/
void			bettermlx_register_loop(t_window *window, \
	void *param, int (*funct_ptr)());

/*
**	Get the current time. (in milliseconds)
**	./bettermlx/time/bettermlx_get_time.c
*/
long long		bettermlx_get_time(void);

#endif
