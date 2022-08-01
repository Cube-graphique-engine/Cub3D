/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:53:21 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/02 18:14:15 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	movement(t_game *game)
{
	if (game->window->keyboard[KEY_W])
	{
		if (game->player->pos.vy - SPPED < 0)
			game->player->pos.vy = 0;
		game->player->pos.vy -= SPPED;
	}
	if (game->window->keyboard[KEY_S])
	{
		if (game->player->pos.vy + SPPED > WIN_HEIGHT)
			game->player->pos.vy += WIN_HEIGHT;
		game->player->pos.vy += SPPED;
	}
	if (game->window->keyboard[KEY_A])
	{
		if (game->player->pos.vx - SPPED < 0)
			game->player->pos.vx = 0;
		game->player->pos.vx -= SPPED;
	}
	if (game->window->keyboard[KEY_D])
	{
		if (game->player->pos.vx + SPPED > WIN_WIDTH)
			game->player->pos.vx += WIN_WIDTH;
		game->player->pos.vx += SPPED;
	}
}