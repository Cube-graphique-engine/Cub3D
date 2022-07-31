/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_function.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:44:43 by mathismartini     #+#    #+#             */
/*   Updated: 2022/07/31 21:44:42 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_CUBE_FUNCTION_H
#define CUBE_CUBE_FUNCTION_H

# include "cube_struct.h"
# include "cube_debug.h"

/* Init */
t_game 	*init_main_struct(void);

/* Parsing */
void	parse_map(t_game *game, char **av);
void	check_format_file_cub(t_game *game, char *path, const char *format);
void	check_format_file_xpm(t_game *game, char *path, const char *format);
void	map_info(t_game *game, char **map);
void	get_map_info(t_game *game);
char	**get_map(t_game *game);
char	*check_path_texture(t_game *game, char *path);

/* Parsing/utils */
t_color	add_color(const char *info, t_game *game);
size_t	size_char_tab(char **tab, size_t index, bool value);
bool	check_base(char **strs, const char *base);
size_t	check_empty_line(char **line, size_t index);
bool	check_line_space(const char *map);
bool	is_in_base(char c, const char *base);
void	get_player_position(t_game *game, char **map);
bool	is_validate_map(t_map *map, int x, int y);


/* Images */
void	get_image_xpm(t_game *game);

#endif
