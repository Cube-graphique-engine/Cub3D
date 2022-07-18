/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:10:03 by mathismartini     #+#    #+#             */
/*   Updated: 2022/07/04 17:37:52 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	error_directory_file(t_game *game)
{
	ft_putstr_errnl("Error ! need a file not a directory");
	free(game->texture);
	free(game->map);
	game->texture = NULL;
	free(game->player);
	game->map = NULL;
	free(game);
	game = NULL;
	exit(EXIT_FAILURE);
}

static void	error_open_file(t_game *game)
{
	ft_putstr_errnl("Error ! Open fail");
	free(game->texture);
	free(game->player);
	free(game->map);
	game->texture = NULL;
	game->map = NULL;
	free(game);
	game = NULL;
	exit(EXIT_FAILURE);
}

static void	error_empty_file(t_game *game)
{
	ft_putstr_errnl("Error ! Empty file");
	free(game->texture);
	free(game->player);
	free(game->map);
	game->texture = NULL;
	game->map = NULL;
	free(game);
	game = NULL;
	exit(EXIT_FAILURE);
}

static void	error_format_file(t_game *game)
{
	ft_putstr_errnl("Error ! need a correct format file need .cub file");
	free(game->texture);
	free(game->player);
	free(game->map);
	game->texture = NULL;
	game->map = NULL;
	free(game);
	game = NULL;
	exit(EXIT_FAILURE);
}

void	check_parse_error(int error, t_game *game)
{
	if (error == FORMAT_FILE)
		error_directory_file(game);
	else if (error == OPEN_FAILURE)
		error_open_file(game);
	else if (error == EMPTY_FILE)
		error_empty_file(game);
	else if (error == NOT_CUB)
		error_format_file(game);
}
