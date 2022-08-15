/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:02:20 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/06 00:14:43 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	close_game(t_game *game)
{
	ft_destroy_string_array(&game->map->map);
	ft_destroy_string_array(&game->map->str_map);
	destroy_game(game);
	free(game->map);
	game->map = NULL;
	free(game->texture);
	game->texture = NULL;
	free(game->player);
	game->player = NULL;
	free(game);
	game = NULL;
	exit (EXIT_SUCCESS);
}

static int	game_loop(t_game *game)
{
	put_floor_and_ceiling(game);
//	put_images_to_window(game);
//	put_player(game, game->player);
	movement(game);
    angle_mov(game);
    display_ray(game);
    if (game->window->keyboard[KEY_ESCAPE])
		close_game(game);
	bettermlx_render(game->window);
	return (0);
}

void	start_game(t_game *game)
{
	game->window = bettermlx_init_window("Cub3D", WIN_WIDTH, WIN_HEIGHT,
			WIN_DIVIDER);
	get_image_xpm(game);
	game_init(game);
	bettermlx_register_loop(game->window, game, game_loop);
}
