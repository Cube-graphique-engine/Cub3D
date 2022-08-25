/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <mathmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:29:50 by mathmart          #+#    #+#             */
/*   Updated: 2022/08/24 20:54:34 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static char	**copy_double_tab(t_game *game, char **file)
{
	char	**copy;
	size_t	i;

	copy = ft_calloc(game->map->height + 1, sizeof(char *));
	i = 0;
	while (i + game->map->start < game->map->end)
	{
		copy[i] = ft_strdup(file[game->map->start + i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	error_map_config(char **map, t_game *game)
{
	printf("Error ! error in map \n");
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
	ft_destroy_string_array(&map);
	ft_destroy_string_array(&game->map->str_map);
	free(game->map);
	free(game->player);
	free(game);
	game = NULL;
	exit(EXIT_FAILURE);
}

static void	check_map(char **map, t_game *game)
{
	size_t	i;
	size_t	x;

	i = 0;
	while (map[i])
	{
		x = 0;
		while (x < ft_strlen(map[i]) && map[i][x])
		{
			if (!is_in_base(map[i][x], "01WNES "))
				error_map_config(map, game);
			x++;
		}
		i++;
	}
}

char	**get_map(t_game *game)
{
	char	**map;

	map_info(game, game->map->file);
	map = copy_double_tab(game, game->map->file);
	check_map(map, game);
	game->map->str_map = copy_double_tab(game, game->map->file);
	ft_destroy_file_content(&game->map->file);
	return (map);
}
