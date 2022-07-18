/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:23:34 by mathismartini     #+#    #+#             */
/*   Updated: 2022/07/17 17:44:40 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static bool	is_in_base(char c, const char *base)
{
	size_t	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
		{
			printf("->%c<-\n", c);
			return (true);
		}
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
			if (is_in_base(map[i][j], "NSEW") == true)
				status++;
			j++;
		}
		i++;
	}
	return (status);
}

static char	**copy_double_tab(char **to_copy, size_t index)
{
	char	**copy;
	size_t	i;

	i = 0;
	copy = ft_calloc(size_char_tab(to_copy, index, true) + 1,
					 sizeof(char *));
	while (to_copy[0 + i])
	{
		copy[i] = ft_strdup(to_copy[0 + i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	get_player_position(t_game *game)
{
	size_t	i;
	size_t	j;
	char	**map;

	map = copy_double_tab(game->map->map, 0);
	printf("OK !\n");
	ft_destroy_string_array(&game->map->map);
	if (check_player(map) > 1
		|| check_player(map) == 0)
		error_player(ERROR_POSITION, game);
	for (int k = 0; map[k]; k++)
		printf("- >%s\n", map[k]);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_in_base(map[i][j], "NSEW") == true)
			{
				printf("i = %zu, j = %zu", i, j);
				game->player->pos_y = j;
				game->player->pos_x = i;
				game->player->orientation = map[i][j];
			}
			j++;
		}
		i++;
	}
	ft_destroy_string_array(&map);
}
