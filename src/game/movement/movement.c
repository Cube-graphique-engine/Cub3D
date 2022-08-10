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

static int  check_wall(t_game *game, int key)
{
    if (key == 0)
    {
        if (game->map->str_map[((int)game->player->pos.vy - 10) / 64][(int)game->player->pos.vx / 64] != '1')
            return (1);
    }
    if (key == 1)
    {
        if (game->map->str_map[((int)game->player->pos.vy + 10) / 64][(int)game->player->pos.vx / 64] != '1')
            return (1);
    }
    if (key == 2)
    {
        if (game->map->str_map[(int)game->player->pos.vy / 64][((int)game->player->pos.vx - 10) / 64] != '1')
            return (1);
    }
    if (key == 3)
    {
        if (game->map->str_map[(int)game->player->pos.vy / 64][((int)game->player->pos.vx + 10) / 64] != '1')
            return (1);
    }
    return (0);
}

void	movement(t_game *game)
{
	if (game->window->keyboard[KEY_W] && check_wall(game, 0))
	{
		if (game->player->pos.vy - SPPED < 0)
			game->player->pos.vy = 0;
		game->player->pos.vy -= SPPED;
	}
	if (game->window->keyboard[KEY_S] && check_wall(game, 1))
	{
		if (game->player->pos.vy + SPPED > WIN_HEIGHT)
			game->player->pos.vy += WIN_HEIGHT;
		game->player->pos.vy += SPPED;
	}
	if (game->window->keyboard[KEY_A] && check_wall(game, 2))
	{
		if (game->player->pos.vx - SPPED < 0)
			game->player->pos.vx = 0;
		game->player->pos.vx -= SPPED;
	}
	if (game->window->keyboard[KEY_D] && check_wall(game, 3))
	{
		if (game->player->pos.vx + SPPED > WIN_WIDTH)
			game->player->pos.vx += WIN_WIDTH;
		game->player->pos.vx += SPPED;
	}
}
