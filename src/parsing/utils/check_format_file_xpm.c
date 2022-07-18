/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:02:38 by mathismartini     #+#    #+#             */
/*   Updated: 2022/07/05 16:12:52 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	error_format_file(t_game *game)
{
	ft_putstr_errnl("Error ! need a correct format file need .xpm file");
	free(game->texture->n_path);
	free(game->texture->s_path);
	free(game->texture->w_path);
	free(game->texture->e_path);
	free(game->map->file);
	free(game->texture);
	free(game->map);
	free(game);
	exit(EXIT_FAILURE);
}

static void	check_format_reverse(const char *path, t_game *game,
		const char *base)
{
	size_t	size;
	size_t	i;

	size = ft_strlen(path) - 4;
	i = 0;
	while (base[i])
	{
		if (base[i] != path[size + i])
			error_format_file(game);
		i++;
	}
}

static void	check_format(const char *path, t_game *game, const char *base)
{
	size_t	size;
	size_t	i;

	size = ft_strlen(path);
	i = ft_strlen(base);
	while (i > 0)
	{
		if (base[i] != path[size])
			error_format_file(game);
		size--;
		i--;
	}
	check_format_reverse(path, game, base);
}

void	check_format_file_xpm(t_game *game, char *path, const char *format)
{
	int	fd;

	check_format(path, game, format);
	fd = open(path, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		error_texture(ERROR_FORMAT, game);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_texture(ERROR_OPEN, game);
	if (read(fd, 0, 0))
		error_texture(ERROR_EMPTY, game);
}
