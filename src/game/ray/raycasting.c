/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 08:22:59 by plavergn          #+#    #+#             */
/*   Updated: 2022/08/14 08:23:02 by plavergn         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int    check_wall_ray(t_game *game, float x, float y, float index_x, float index_y)
{
    if (game->map->str_map[(((int)index_y + (int)y)) / 64][((int)index_x + (int)x) / 64] != '1')
        return (1);
    return (0);
}

void    display_ray_left(t_game *game, float incr, float limit, int y)
{
    int verif;
    float index_y;
    float index_x;

        verif = 0;
        if (incr < limit)
            verif = -1;
        if (incr > limit)
            verif = 1;
         while (verif != 0)
         {
             index_y = game->player->pos.vy;
            index_x = game->player->pos.vx;
            while (check_wall_ray(game, incr, -1, index_x, index_y))
           {
               index_x += incr;
               index_y += y;
               bettermlx_pixel_put(game->window, create_vector(index_x, index_y, 0),  create_icolor(0, 0, 0, 0), 1);
           }
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
        display_ray_left(game, 1, -1, -1);
    if (game->player->angle == 0)
    {
        display_ray_left(game, 1, 0, 1);
//        display_ray_left(game, 6);
    }
//    if (game->player->angle == 180)
//    {
//        display_ray_left(game, 0.5);
//        display_ray_left(game, -1.5);
//    }
    if (game->player->angle == 270)
    {
        display_ray_left(game, 1, -1, 1);
    }
}

void    display_ray(t_game *game)
{
    display_ray_north(game);
}