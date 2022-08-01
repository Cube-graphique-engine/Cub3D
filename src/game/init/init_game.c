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

void	game_init(t_game *game)
{
	bettermlx_hook(game->window, KEY_PRESS, &key_press_hook, game);
	bettermlx_hook(game->window, KEY_RELEASE, &key_release_hook, game);
	mlx_hook(game->window->win_ptr, 17, 1L << 5, &close_game, game);
	game->player->pos = create_vector((float)game->player->pos_x, (float)game->player->pos_y, 0);
}
