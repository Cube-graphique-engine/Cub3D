/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 00:00:55 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/22 14:57:00 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static t_ray	*init_ray(void)
{
	t_ray	*ray;

	ray = ft_calloc(1, sizeof(t_ray));
	return (ray);
}

static void	add_player_info(t_player *player)
{
	player->fov = 0.66f;
	player->sensi = 0.015f;
	player->speed = 0.05f;
	init_player_orientation(player);
}

void	game_init(t_game *game)
{
	bettermlx_hook(game->window, KEY_PRESS, &key_press_hook, game);
	bettermlx_hook(game->window, KEY_RELEASE, &key_release_hook, game);
	mlx_hook(game->window->win_ptr, 17, 1L << 5, &close_game, game);
	add_player_info(game->player);
	mlx_mouse_hide();
	mlx_mouse_move(game->window->win_ptr, WIN_HEIGHT * 0.5, WIN_WIDTH * 0.5);
	game->ray = init_ray();
}
