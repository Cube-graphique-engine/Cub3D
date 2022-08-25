/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_function.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:44:43 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/24 15:07:34 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_FUNCTION_H
# define CUBE_FUNCTION_H

# include "cube_struct.h"
# include "cube_debug.h"

/* init */
t_game	*init_main_struct(void);

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
void	check_numbers(const char *info, t_game *game);
void	check_info(const char *info, int index, t_game *game);

/* ************************************************************************** */
/*									Start_Game								  */
/* ************************************************************************** */

void	start_game(t_game *game);
int		close_game(t_game *game);

/* game/images */
void	get_image_xpm(t_game *game);

/* game/init */
void	init_player_orientation(t_player *player);
void	game_init(t_game *game);

/* game/movement */
void	player_move(t_game *game, t_window *window);
void	rotate_left(t_player *player);
void	rotate_right(t_player *player);
void	use_mouse(t_game *game);

/* game/raycasting */
void	do_raycast(t_game *game);
void	ray_step(t_player *player, t_ray *ray);
void	init_ray_size(t_ray *ray);
void	display_walls(t_game *game, t_ray *ray, t_vector3 i);
void	display_line(t_game *game, t_ray *ray, int x);

/* game/utils */
int		key_press_hook(int key_code, t_game *game);
int		key_release_hook(int key_code, t_game *game);
void	destroy_game(t_game *game);
void	draw_cube(float size, t_vector3 vec, t_color color, t_game *game);
void	draw_cube_left(float size, t_vector3 vec, t_color color, t_game *game);

/* game/window */
void	put_images_to_window(t_game *game);

#endif
