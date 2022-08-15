/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 08:22:59 by plavergn          #+#    #+#             */
/*   Updated: 2022/08/15 11:52:52 by plavergn         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int check_wall_ray(t_game *game, float x, float y, float index_x_y[2])
{
	if (game->map->str_map[(int)((index_x_y[1] \
		+ y) * 0.015625)][(int)((index_x_y[0] + x) * 0.015625)] != '1')
		return (1);
	return (0);
}

int check_x_negative(float incr)
{
	(void)incr;
	return (0);
}

int check_x_positive(float incr)
{
	return ((int)((incr + 1) * 1000));
}

int check_x_pos(float incr, int verif)
{
	if (verif == -1)
	{
		return (check_x_negative(incr));
	}
	else if (verif == 1)
	{
		return (check_x_positive(incr));
	}
	return (0);
}

void    view_wall(t_game *game, int x_right, int height)
{
	int index;
	int y;

	y = (WIN_HEIGHT - height) * 0.5;
	while (y < (height + (1080 - height) * 0.5))
	{
		index = 0;
		while (index < 10)
		{
			bettermlx_pixel_put(game->window, create_vector(x_right + index, y, \
					0),  create_icolor(0, 0, 0, 0), 1);
			index++;
		}
		y++;
	}
}

void    put_wall(t_game *game, int index, float incr, int verif)
{
	int height;
	int x_right;

	if (index > 540)
		return ;
	height = (index - 541) * -2;
//	height = index * cos
	x_right = check_x_pos(incr, verif);
	view_wall(game, x_right, height);
}

int check_verif(float incr, float limit)
{
	if (incr < limit)
		return (-1);
	if (incr > limit)
		return (1);
	return (0);
}



void    display_ray_left(t_game *game, float incr, float limit, int y)
{
	int verif;
	int index;
	float index_x_y[2];

	verif = check_verif(incr, limit);
	while (verif != 0)
	{
		index_x_y[0] = game->player->pos.vx;
		index_x_y[1] = game->player->pos.vy;
		while (check_wall_ray(game, incr, -1, index_x_y))
		{
			index++;
			index_x_y[0] += incr;
			index_x_y[1] += y;
		}
		put_wall(game, index, incr, verif);
		index = 0;
		if (incr > limit && verif == 1)
			incr -= 0.01;
		else if (incr < limit && verif == -1)
			incr += 0.01;
		else
			verif = 0;
	}
}

void    display_ray_north(t_game *game)
{
	if (game->player->angle == 90)
		display_ray_left(game, 0.92, -1, -1);
}

void    display_ray(t_game *game)
{
	display_ray_north(game);
}
