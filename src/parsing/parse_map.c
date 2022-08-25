/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:51:42 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/24 15:07:35 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//game->map->file destroy in get_map()

//static void	need_to_be_free(t_game *game)
//{
//	free(game->texture->n_path);
//	free(game->texture->s_path);
//	free(game->texture->w_path);
//	free(game->texture->e_path);
//	if (game->debug)
//	{
//		free(game->texture->d_ceilling);
//		free(game->texture->d_floor);
//	}
//	free(game->texture);
//	ft_destroy_string_array(&game->map->map);
//	ft_destroy_string_array(&game->map->str_map);
//	free(game->map);
//	free(game->player);
//	free(game);
//	game = NULL;
//}

void	parse_map(t_game *game, char **av)
{
	check_format_file_cub(game, av[1], ".cub");
	game->map->file = ft_get_file_content(av[1]);
	get_map_info(game);
	game->map->map = get_map(game);
	get_player_position(game, game->map->map);
	if (!is_validate_map(game->map, (int)game->player->pos_x,
			(int)game->player->pos_y))
		error_map(MAP_CLOSE, game);
}

//	display_info(game);
//	need_to_be_free(game);
