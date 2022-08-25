/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:23:02 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/24 16:41:38 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	error_directory(t_game *game)
{
	ft_putstr_errnl("Error ! need a file not a directory");
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

static void	error_config(t_game *game)
{
	ft_putstr_errnl("Error ! Incorrect configuration information");
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

static void	error_open_file(t_game *game)
{
	ft_putstr_errnl("Error ! Open fail #xpm");
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

static void	error_empty_file(t_game *game)
{
	ft_putstr_errnl("Error ! Empty file");
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

void	error_texture(int error, t_game *game)
{
	if (error == CONFIG_ERROR)
		error_config(game);
	else if (error == ERROR_FORMAT)
		error_directory(game);
	else if (error == ERROR_OPEN)
		error_open_file(game);
	else if (error == ERROR_EMPTY)
		error_empty_file(game);
}
