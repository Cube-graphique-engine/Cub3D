/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <mathmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:29:50 by mathmart          #+#    #+#             */
/*   Updated: 2022/07/31 23:06:15 by mathismartini    ###   ########.fr       */
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

char	**get_map(t_game *game)
{
	char	**map;

	map_info(game, game->map->file);
	map = copy_double_tab(game, game->map->file);
	ft_destroy_file_content(&game->map->file);
	return (map);
}
