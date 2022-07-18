/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:51:42 by mathismartini     #+#    #+#             */
/*   Updated: 2022/07/25 18:52:29 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	parse_map(t_game *game, char **av)
{
	check_format_file_cub(game, av[1], ".cub");
	game->map->file = ft_get_file_content(av[1]);
	get_map_info(game);
	game->map->map = get_map(game);
	get_player_position(game, game->map->map);
}
