/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:56:16 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/24 19:49:23 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	error_position(t_game *game)
{
	ft_putstr_errnl("Error ! Player position");
	free(game->texture->n_path);
	free(game->texture->s_path);
	free(game->texture->w_path);
	free(game->texture->e_path);
	if (game->debug)
	{
		free(game->texture->d_ceilling);
		free(game->texture->d_floor);
	}
	free(game->texture);
	ft_destroy_string_array(&game->map->map);
	ft_destroy_string_array(&game->map->str_map);
	free(game->map);
	free(game->player);
	free(game);
	game = NULL;
	exit(EXIT_FAILURE);
}

static void	error_config_map(t_game *game)
{
	ft_putstr_errnl("Error ! Map");
	free(game->texture->n_path);
	free(game->texture->s_path);
	free(game->texture->w_path);
	free(game->texture->e_path);
	if (game->debug)
	{
		free(game->texture->d_ceilling);
		free(game->texture->d_floor);
	}
	free(game->texture);
	ft_destroy_string_array(&game->map->map);
	ft_destroy_string_array(&game->map->str_map);
	free(game->map);
	free(game->player);
	free(game);
	game = NULL;
	exit(EXIT_FAILURE);
}

void	error_player(int error, t_game *game)
{
	if (error == ERROR_POSITION)
		error_position(game);
	else if (error == ERROR_CONFIG_MAP)
		error_config_map(game);
}
