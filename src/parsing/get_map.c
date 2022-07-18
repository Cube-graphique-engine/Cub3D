/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <mathmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:29:50 by mathmart          #+#    #+#             */
/*   Updated: 2022/07/25 18:53:44 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static size_t	get_map_height(char **map, t_game *game)
{
	size_t	i;

	i = ft_get_splitted_size(map) - 1;
	while (i > 0)
	{
		if (!is_in_base(map[i][0], "10NSEW "))
			break ;
		i--;
	}
	if (i == 0)
		error_map(MAP_HEIGHT, game);
	if (check_line_space(map[i]))
		i++;
	return (i);
}

static size_t	get_map_width(char **map, t_game *game)
{
	size_t	i;
	size_t	size;

	game->map->height = get_map_height(game->map->file, game);
	i = ft_get_splitted_size(map) - 1 - game->map->height;
	size = 0;
	game->map->start = i;
	while (map[i])
	{
		if (ft_strlen(map[i]) > size)
			size = ft_strlen(map[i]);
		i++;
	}
	return (size);
}

static char	**copy_double_tab(t_game *game, char **file)
{
	char	**copy;
	size_t	i;

	game->map->width = get_map_width(file, game);
	copy = ft_calloc(game->map->height + 1, sizeof(&copy));
	i = 0;
	while (file[game->map->start + i] && i < game->map->height)
	{
		copy[i] = ft_strdup(file[game->map->start + i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

char	**get_map(t_game *game)
{
	char	**map;

	map = copy_double_tab(game, game->map->file);
	ft_destroy_file_content(&game->map->file);
	return (map);
}
