/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 22:27:17 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/06 00:09:04 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static size_t	get_map_start(char **map, t_game *game)
{
	size_t	i;

	i = ft_get_splitted_size(map) - 1;
	i = check_empty_line(map, i);
	while (i > 0)
	{
		if (!is_in_base(map[i][0], "10NSEW "))
			break ;
		i--;
	}
	if (i == 0)
		error_map(MAP_HEIGHT, game);
	if (check_line_space(map[i]) || is_in_base(map[i][0], "CF"))
		i++;
	return (i);
}

static size_t	get_map_end(char **map, t_game *game)
{
	size_t	i;

	i = game->map->start;
	while (map[i])
	{
		if (!is_in_base(map[i][0], "10NSEW "))
			break ;
		i++;
	}
	return (i);
}

static size_t	get_map_width(char **map, t_game *game)
{
	size_t	i;
	size_t	size;

	i = game->map->start;
	size = 0;
	while (i < game->map->end)
	{
		if (ft_strlen(map[i]) > size)
			size = ft_strlen(map[i]);
		i++;
	}
	return (size);
}

void	map_info(t_game *game, char **map)
{
	game->map->start = get_map_start(map, game);
	game->map->end = get_map_end(map, game);
	game->map->height = game->map->end - game->map->start;
	game->map->width = get_map_width(map, game);
    game->map->size = game->map->height * game->map->width;
}
