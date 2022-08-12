/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 00:00:55 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/02 00:35:52 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	get_real_position(t_player *player)
{
	float	real_y;
	float	real_x;

	printf("%d  %d\n", player->pos_x, player->pos_y);
	real_y = (float)(player->pos_y * 64) + 32;
	real_x = (float)(player->pos_x * 64) + 32;
	player->pos.vx = real_x;
	player->pos.vy = real_y;
}


void	game_init(t_game *game)
{
	bettermlx_hook(game->window, KEY_PRESS, &key_press_hook, game);
	bettermlx_hook(game->window, KEY_RELEASE, &key_release_hook, game);
	mlx_hook(game->window->win_ptr, 17, 1L << 5, &close_game, game);
	game->player->size = 16;
	game->player->half_size = (float)(game->player->size * 0.5);
	get_real_position(game->player);
}
