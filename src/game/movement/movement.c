/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:53:21 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/15 19:41:20 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int  check_wall(t_game *game, int key)
{
	if (key == 0)
	{
		if (game->map->str_map[(int)((game->player->pos.vy - 0.2) * 0.015625)] \
        	[(int)(game->player->pos.vx * 0.015625)] != '1')
			return (1);
	}
	if (key == 1)
	{
		if (game->map->str_map[(int)((game->player->pos.vy + 0.2) * 0.015625)] \
        	[(int)(game->player->pos.vx * 0.015625)] != '1')
			return (1);
	}
	if (key == 2)
	{
		if (game->map->str_map[(int)(game->player->pos.vy * 0.015625)] \
			[(int)((game->player->pos.vx - 0.2) * 0.015625)] != '1')
			return (1);
	}
	if (key == 3)
	{
		if (game->map->str_map[(int)(game->player->pos.vy * 0.015625)] \
			[(int)((game->player->pos.vx + 0.2) * 0.015625)] != '1')
			return (1);
	}
	return (0);
}

void	movement(t_game *game)
{
	if (game->window->keyboard[KEY_LEFT])
	{
		game->player->cam.vy -= 0.2;
	}
	if (game->window->keyboard[KEY_RIGHT])
	{
		game->player->cam.vy += 0.2;
	}
	if (game->window->keyboard[KEY_W] && check_wall(game, 0))
	{
		game->player->pos.vy -= 0.2;
		printf("W");
	}
	if (game->window->keyboard[KEY_S] && check_wall(game, 1))
	{
		game->player->pos.vy += 0.2;
		printf("S");
	}
	if (game->window->keyboard[KEY_A] && check_wall(game, 2))
	{
		game->player->pos.vx -= 0.2;
		printf("A");
	}
	if (game->window->keyboard[KEY_D] && check_wall(game, 3))
	{
		game->player->pos.vx += 0.2;
		printf("D");
	}
}

/*
static int  check_wall(t_game *game, int key)
{
    if (key == 0)
    {
        if (game->map->str_map[((int)game->player->pos.vy - 10) / 64] \
        	[(int)game->player->pos.vx / 64] != '1')
            return (1);
    }
    if (key == 1)
    {
        if (game->map->str_map[((int)game->player->pos.vy + 10) / 64]\
        	[(int)game->player->pos.vx / 64] != '1')
            return (1);
    }
    if (key == 2)
    {
        if (game->map->str_map[(int)(game->player->pos.vy * 0.015625)] \
			[(int)((game->player->pos.vx) * 0.015625)] != '1')
            return (1);
    }
    if (key == 3)
    {
        if (game->map->str_map[(int)(game->player->pos.vy * 0.015625)] \
			[(int)((game->player->pos.vx) * 0.015625)] != '1')
            return (1);
    }
    return (0);
}

void	movement(t_game *game, t_player *player)
{
	(void)player;
	if (game->window->keyboard[KEY_W] && check_wall(game, 0/
			player->half_size))
	{
		if (game->player->pos.vy - SPEED < 64 + SPEED + 0.5)
			game->player->pos.vy = 64;
		game->player->pos.vy -= SPEED;
	}
	if (game->window->keyboard[KEY_S] && check_wall(game, 1/
			player->half_size))
	{
		if (game->player->pos.vy + SPEED > WIN_HEIGHT)
			game->player->pos.vy += WIN_HEIGHT;
		game->player->pos.vy += SPEED;
	}
	if (game->window->keyboard[KEY_A] && check_wall(game, 2/
			player->half_size))
	{
		if (game->player->pos.vx - SPEED < 64 + SPEED + 0.5)
			game->player->pos.vx = 64 + 0.5;
		game->player->pos.vx -= SPEED;
	}
	if (game->window->keyboard[KEY_D] && check_wall(game, 3/
			player->half_size))
	{
		if (game->player->pos.vx + SPEED > WIN_WIDTH)
			game->player->pos.vx += WIN_WIDTH;
		game->player->pos.vx += SPEED;
	}
}
*/