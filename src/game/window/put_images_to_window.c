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

//static void	draw_vertex(t_game *game, t_cube_coo *coord, t_color color)
//{
//	t_vector3	vec;
//
//	vec.vy = coord->up_left.vy;
//	while (coord->up_left.vy + vec.vy < coord->down_left.vy)
//	{
//		vec.vx = coord->up_left.vx;
//		while (coord->up_left.vx + vec.vx < coord->up_right.vx)
//		{
//			bettermlx_pixel_put(game->window, vec, color, 1);
//			vec.vx++;
//		}
//		vec.vy++;
//	}
//}

//static void	add_coord(t_cube_coo *coord, float x, float y, float size)
//{
//	coord->up_left = create_vector(x * size, y * size, 0);
//	coord->down_left = create_vector(x * size, y * size + size, 0);
//	coord->up_right = create_vector(x * size + size, y * size, 0);
//	coord->down_right = create_vector(x * size + size, y * size + size, 0);
//}

//void	draw_2d_map(t_game *game, float size)
//{
//	t_color	color;
//	size_t	x;
//	size_t	y;
//
//	y = 0;
//	while (y < game->map->height)
//	{
//		x = 0;
//		while (x < ft_strlen(game->map->str_map[y]))
//		{
//			if (game->map->str_map[y][x] == '1')
//				color = create_icolor(1, 255, 255, 255);
//			else
//				color = create_icolor(0, 0, 0, 0);
//			add_coord(&game->coord, x, y, size);
//			draw_vertex(game, &game->coord, color);
//			x++;
//		}
//		y++;
//	}
//}

static t_vector3 get_vec(size_t y, size_t x, float size)
{
    float new_y;
    float new_x;

    new_y = size * y - 0.5;
    new_x = size * x - 0.5;
    return (create_vector(new_x, new_y, 0));
}

void	draw_2d_map(t_game *game, float size)
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
            if (game->map->bit_map[y* ft_strlen(game->map->str_map[y]) + x] == 1)
                color = create_icolor(1, 255, 255, 255);
            else
                color = create_icolor(0, 0, 0, 0);
            draw_cube_left(size, get_vec(y, x, size), color, game);
            x++;
        }
        y++;
    }
}

static void convert_map(t_map *map)
{
    size_t  x;
    size_t  y;
    size_t  index;

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
//	t_color		color;
//
//	color = create_icolor(1, 255, 12, 122);
//	draw_2d_cub(game);
//	draw_player(game);
//	draw_cube_left(40, create_vector( WIN_WIDTH /2, WIN_HEIGHT /2, 0), create_icolor(1, 0, 28, 227), game);
//	draw_cube(80, create_vector(WIN_WIDTH /2, WIN_HEIGHT /2, 0), color, game);
}

