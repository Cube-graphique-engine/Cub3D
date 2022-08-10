/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images_to_window.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 00:08:17 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/08 23:56:11 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static t_vector3	get_vec(size_t y, size_t x, float size)
{
	float	new_y;
	float	new_x;

	new_y = size * y - 0.5;
	new_x = size * x - 0.5;
	return (create_vector(new_x, new_y, 0));
}

static t_color 	get_color(size_t y, t_game *game)
{
	if (y < WIN_HEIGHT * 0.5)
		return (game->texture->ceiling);
	else
		return (game->texture->floor);
}

static void	draw_2d_map(t_game *game, float size)
{
	t_color	color;
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < ft_strlen(game->map->str_map[y]))
		{
			if (game->map->bit_map[y * \
				ft_strlen(game->map->str_map[y]) + x] == 1)
				color = create_icolor(1, 255, 255, 255);
			else
				color = get_color(y, game);
			draw_cube_left(size, get_vec(y, x, size), color, game);
			x++;
		}
		y++;
	}
}

static void	convert_map(t_map *map)
{
	size_t	x;
	size_t	y;
	size_t	index;

	map->bit_map = ft_calloc(map->size + 1, sizeof(int));
	if (!map->bit_map)
		return ;
	y = 0;
	index = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < ft_strlen(map->str_map[y]))
		{
			if (map->str_map[y][x] == '1')
				map->bit_map[index] = 1;
			else
				map->bit_map[index] = 0;
			index++;
			x++;
		}
		y++;
	}
	ft_destroy_string_array(&map->map);
}

void	put_images_to_window(t_game *game)
{
	convert_map(game->map);
	draw_2d_map(game, 64);
}
