/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 19:40:09 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/24 19:41:09 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	error_colors(t_game *game)
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

void	check_numbers(const char *info, t_game *game)
{
	size_t	i;

	i = ft_strlen(info) - 1;
	while (info[i] != ',')
	{
		if (!is_numeric(info[i]))
			error_colors(game);
		i--;
	}
}

void	check_info(const char *info, int index, t_game *game)
{
	int		i;
	size_t	count;

	i = index - 1;
	while (info[++i])
		if (!is_numeric(info[i]) || info[i] != ',')
			i++;
	count = 0;
	while (i > index)
	{
		if (info[i] == ',')
			count++;
		i--;
	}
	if (count != 2)
		error_colors(game);
}
