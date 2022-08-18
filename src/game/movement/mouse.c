/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 22:41:19 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/18 22:47:05 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	use_mouse(t_game *game)
{
	int			delta;
	int			x;
	int			y;

	mlx_mouse_get_pos(game->window->win_ptr, &x, &y);
	delta = WIN_WIDTH * 0.5 - x;
	if (delta > WIN_WIDTH * 0.5 + 1)
	{
		game->player->sensi = delta * 0.001;
		rotate_left(game->player);
	}
	else if (delta < WIN_WIDTH * 0.5 - 1)
	{
		game->player->sensi = (float)-delta * 0.001;
		rotate_right(game->player);
	}
	mlx_mouse_move(game->window->win_ptr, WIN_WIDTH * 0.5, WIN_HEIGHT * 0.5);
}
