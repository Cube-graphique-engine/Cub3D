/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_errors.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:11:41 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/20 19:19:32 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_ERRORS_H
# define CUBE_ERRORS_H

typedef enum e_error
{
	FORMAT_FILE,
	OPEN_FAILURE,
	EMPTY_FILE,
	NOT_CUB
}			t_error;

typedef enum e_error_texture
{
	CONFIG_ERROR,
	ERROR_FORMAT,
	ERROR_OPEN,
	ERROR_EMPTY,
}			t_error_texture;

typedef enum e_error_player
{
	ERROR_POSITION,
	ERROR_CONFIG_MAP
}			t_error_player;

typedef enum e_error_map
{
	MAP_HEIGHT,
	MAP_CLOSE
}			t_error_map;

void	check_parse_error(int error, t_game *game);
void	error_texture(int error, t_game *game);
void	error_player(int error, t_game *game);
size_t	error_map(int error, t_game *game);

#endif
