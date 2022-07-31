/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 01:49:11 by mathismartini     #+#    #+#             */
/*   Updated: 2022/07/25 18:55:43 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	error_height(t_game *game)
{
	ft_putstr_errnl("Error ! Map height incorrect");
	free(game->texture->n_path);
	free(game->texture->s_path);
	free(game->texture->w_path);
	free(game->texture->e_path);
	free(game->map->file);
	free(game->player);
	free(game->texture);
	ft_destroy_string_array(&game->map->map);
	free(game);
	exit(EXIT_FAILURE);
}

static void	error_close(t_game *game)
{
	ft_putstr_errnl("Error ! Map Not close");
	free(game->texture->n_path);
	free(game->texture->s_path);
	free(game->texture->w_path);
	free(game->texture->e_path);
	free(game->map->file);
	free(game->player);
	free(game->texture);
	ft_destroy_string_array(&game->map->map);
	free(game);
	exit(EXIT_FAILURE);
}

size_t	error_map(int error, t_game *game)
{
	if (error == MAP_HEIGHT)
		error_height(game);
	else if (error == MAP_CLOSE)
		error_close(game);
	return (0);
}
