/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_function.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:44:43 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/02 17:53:15 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_CUBE_FUNCTION_H
#define CUBE_CUBE_FUNCTION_H

# include "cube_struct.h"
# include "cube_debug.h"

/* init */
t_game 	*init_main_struct(void);

/* ************************************************************************** */
/*									Parsing									  */
/* ************************************************************************** */

void	parse_map(t_game *game, char **av);
void	check_format_file_cub(t_game *game, char *path, const char *format);
void	check_format_file_xpm(t_game *game, char *path, const char *format);
void	map_info(t_game *game, char **map);
void	get_map_info(t_game *game);
char	**get_map(t_game *game);
char	*check_path_texture(t_game *game, char *path);

/* Parsing/utils */
t_color	add_color(const char *info, t_game *game);
size_t	check_empty_line(char **line, size_t index);
bool	check_line_space(const char *map);
bool	is_in_base(char c, const char *base);
void	get_player_position(t_game *game, char **map);
bool	is_validate_map(t_map *map, int x, int y);

/* ************************************************************************** */
/*									Start_Game								  */
/* ************************************************************************** */

void	start_game(t_game *game);
int		close_game(t_game *game);

/* game/utils */
int		key_press_hook(int key_code, t_game *game);
int		key_release_hook(int key_code, t_game *game);
void	destroy_game(t_game *game);
void	game_init(t_game *game);
void	draw_cube(float size, t_vector3 vec, t_color color, t_game *game);
void	draw_cube_left(float size, t_vector3 vec, t_color color, t_game *game);

/* Gmae/window */
void	put_images_to_window(t_game *game);

/* game/movement */
void	movement(t_game *game);

/* Images */
void	get_image_xpm(t_game *game);

#endif
