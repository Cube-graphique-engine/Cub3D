/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:02:20 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/01 17:34:06 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	close_game(t_game *game)
{
	ft_destroy_string_array(&game->map->map);
	ft_destroy_string_array(&game->map->str_map);
	destroy_game(game);
	free(game->map);
	game->map = NULL;
	free(game->player);
	game->player = NULL;
	free(game);
	game = NULL;
	exit (EXIT_SUCCESS);
}

static int	game_loop(t_game * game)
{
	if (game->window->keyboard[KEY_ESCAPE])
		close_game(game);
	return (0);
}

void	start_game(t_game *game)
{
	game->window = bettermlx_init_window("Cub3D", WIN_WIDTH, WIN_HEIGHT,
		 WIN_DIVIDER);
	get_image_xpm(game);
	bettermlx_hook(game->window, KEY_PRESS, &key_press_hook, game);
	bettermlx_hook(game->window, KEY_RELEASE, &key_release_hook, game);
	mlx_hook(game->window->win_ptr, 17, 1L << 5, &close_game, game);
	bettermlx_register_loop(game->window, game, game_loop);
}
