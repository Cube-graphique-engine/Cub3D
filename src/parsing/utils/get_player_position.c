/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:23:34 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/01 00:05:15 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static bool	p_is_in_base(char c, const char *base)
{
	size_t	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (true);
		i++;
	}
	return (false);
}

static size_t	check_player(char **map)
{
	size_t	i;
	size_t	j;
	size_t	status;

	i = 0;
	status = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (p_is_in_base(map[i][j], "NSEW") == true)
				status++;
			j++;
		}
		i++;
	}
	return (status);
}

void	get_player_position(t_game *game, char **map)
{
	size_t	i;
	size_t	j;

	if (check_player(map) > 1
		|| check_player(map) == 0)
		error_player(ERROR_POSITION, game);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_in_base(map[i][j], "NSEW") == true)
			{
				game->player->pos_y = i;
				game->player->pos_x = j;
				game->player->orientation = map[i][j];
			}
			j++;
		}
		i++;
	}
}
