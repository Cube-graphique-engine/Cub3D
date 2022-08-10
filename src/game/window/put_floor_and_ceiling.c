/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_floor_and_ceiling.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:06:21 by mathmart          #+#    #+#             */
/*   Updated: 2022/08/10 15:06:22 by mathmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	put_floor(t_game *game, float start, t_color color)
{
	float		x;
	t_vector3	vector;

	printf("start = %f\n", start);
	while (start < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			vector = create_vector(x, start, 0);
			bettermlx_pixel_put(game->window, vector, color, 1);
			x++;
		}
		start++;
	}
}

static void	put_ceiling(t_game *game, float max, t_color color)
{
	float		x;
	float		y;
	t_vector3	vector;

	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			vector = create_vector(x, y, 0);
			bettermlx_pixel_put(game->window, vector, color, 1);
			x++;
		}
		y++;
	}
}

void	put_floor_and_ceiling(t_game *game)
{
	put_floor(game, WIN_HEIGHT * 0.5, game->texture->floor);
	put_ceiling(game, WIN_HEIGHT * 0.5, game->texture->ceiling);
}
