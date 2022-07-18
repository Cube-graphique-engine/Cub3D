/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_errors.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:11:41 by mathismartini     #+#    #+#             */
/*   Updated: 2022/07/11 15:09:01 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_CUBE_ERRORS_H
#define CUBE_CUBE_ERRORS_H

typedef enum s_error
{
	FORMAT_FILE,
	OPEN_FAILURE,
	EMPTY_FILE,
	NOT_CUB
}			t_error;

typedef enum s_error_texture
{
	CONFIG_ERROR,
	ERROR_FORMAT,
	ERROR_OPEN,
	ERROR_EMPTY,
}			t_error_texture;

typedef enum s_error_player
{
	ERROR_POSITION,
	ERROR_CONFIG_MAP
}			t_error_player;

typedef enum s_error_map
{
	MAP_HEIGHT,
	MAP_WIDTH
}			t_error_map;

void	check_parse_error(int error, t_game *game);
void	error_texture(int error, t_game *game);
void	error_player(int error, t_game *game);
size_t	error_map(int error, t_game *game);

#endif
