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
        if (game->map->str_map[(int)(game->player->pos.vy * 0.015625)] \
			[(int)((game->player->pos.vx - game->player->size) * 0.015625)] != '1')
            return (1);
    }
    if (key == 3)
    {
        if (game->map->str_map[(int)(game->player->pos.vy * 0.015625)] \
			[(int)((game->player->pos.vx + game->player->size) * 0.015625)] != '1')
            return (1);
    }
    return (0);
}
// 0 = UP
// 1 = DOWN
// 2 = LEFT
// 3 = RIGHT

//static int	check_wall(t_game *game, int key, float size)
//{
//	if (key == 0)
//		if (game->map->str_map[(int)((game->player->pos.vy - size) * 0.015625)] \
//			[(int)(game->player->pos.vx * 0.015625)] != '1')
//			return (1);
//	if (key == 1)
//		if (game->map->str_map[(int)((game->player->pos.vy + size) * 0.015625)] \
//			[(int)(game->player->pos.vx * 0.015625)] != '1')
//			return (1);
//	if (key == 2)
//		if (game->map->str_map[(int)(game->player->pos.vy * 0.015625)] \
//			[(int)((game->player->pos.vx - size) * 0.015625)] != '1')
//			return (1);
//	if (key == 3)
//		if (game->map->str_map[(int)(game->player->pos.vy * 0.015625)] \
//			[(int)((game->player->pos.vx + size) * 0.015625)] != '1')
//			return (1);
//	return (0);
//}

void	movement(t_game *game)
{
	if (game->window->keyboard[KEY_W] && check_wall(game, 0/*player->half_size*/))
	{
		if (game->player->pos.vy - SPPED < 64 + SPPED + 0.5)
			game->player->pos.vy = 64;
		game->player->pos.vy -= SPPED;
	}
	if (game->window->keyboard[KEY_S] && check_wall(game, 1/*player->half_size*/))
	{
		if (game->player->pos.vy + SPPED > WIN_HEIGHT)
			game->player->pos.vy += WIN_HEIGHT;
		game->player->pos.vy += SPPED;
	}
	if (game->window->keyboard[KEY_A] && check_wall(game, 2/*player->half_size*/))
	{
		if (game->player->pos.vx - SPPED < 64 + SPPED + 0.5)
			game->player->pos.vx = 64 + 0.5;
		game->player->pos.vx -= SPPED;
	}
	if (game->window->keyboard[KEY_D] && check_wall(game, 3/*player->half_size*/))
	{
		if (game->player->pos.vx + SPPED > WIN_WIDTH)
			game->player->pos.vx += WIN_WIDTH;
		game->player->pos.vx += SPPED;
	}
}

void	angle_mov(t_game *game)
{
    if (game->window->keyboard[KEY_LEFT])
    {
        game->player->angle += 10;
    }
    if (game->window->keyboard[KEY_RIGHT])
    {
        game->player->angle -= 10;
    }
    if (game->player->angle < 0)
        game->player->angle = 360 + game->player->angle;
    if (game->player->angle > 360)
        game->player->angle = game->player->angle - 360;
    printf("angle : %f\n", game->player->angle);
}

