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
	free(game->map);
	free(game);
	exit(EXIT_FAILURE);
}

size_t	error_map(int error, t_game *game)
{
	if (error == MAP_HEIGHT)
		error_height(game);
	return (0);
}
