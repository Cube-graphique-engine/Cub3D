/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cube_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:50:28 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/02 18:54:16 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//static void	draw_right_down_side(float size, t_vector3 vec, t_color color, t_game *game)
//{
//	float 		y;
//	float 		x;
//	t_vector3	vec_tmp;
//
//	y = 0;
//	vec_tmp = vec;
//	while (y < size / 2)
//	{
//		x = 0;
//		vec.vx = vec_tmp.vx;
//		while (x < size)
//		{
//			bettermlx_pixel_put(game->window, vec, color, 1);
//			x++;
//			vec.vx++;
//		}
//		y++;
//		vec.vy++;
//	}
//}
//
//static void	draw_upper_right_side(float size, t_vector3 vec, t_color color, t_game *game)
//{
//	float		y;
//	float		x;
//	t_vector3	vec_tmp;
//
//	y = 0;
//	vec_tmp = vec;
//	while (y < size / 2)
//	{
//		x = 0;
//		vec.vx = vec_tmp.vx;
//		while (x < size)
//		{
//			bettermlx_pixel_put(game->window, vec, color, 1);
//			x++;
//			vec.vx++;
//		}
//		y++;
//		vec.vy--;
//	}
//}

static void	draw_side(float size, t_vector3 vec, t_color color, t_game *game)
{
    float		y;
    float		x;
    t_vector3	vec_tmp;

    y = 0;
    vec_tmp = vec;
    while (y < size)
    {
        x = 0;
        vec.vx = vec_tmp.vx;
        while (x < size)
        {
            bettermlx_pixel_put(game->window, vec, color, 1);
            x++;
            vec.vx++;
        }
        y++;
        vec.vy++;
    }
}

//	draw_right_down_side(size, vec, color, game);
//	draw_upper_right_side(size, vec, color, game);

void	draw_cube_left(float size, t_vector3 vec, t_color color, t_game *game)
{
    draw_side(size, vec, color, game);
}
