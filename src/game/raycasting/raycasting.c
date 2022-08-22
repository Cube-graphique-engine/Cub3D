/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:30:57 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/22 15:47:36 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	init_rays(t_player *player, t_ray *ray, int i)
{
	ray->screenx = 2.0f * (float)i / (float)WIN_WIDTH - 1.0f;
	ray->ray_dist = create_vector(player->direction.vx + player->cam.vx * \
		ray->screenx, player->direction.vy + player->cam.vy * ray->screenx, 0);
	if (ray->ray_dist.vx == 0)
		ray->ray_dist.vx = 1e-30;
	if (ray->ray_dist.vy == 0)
		ray->ray_dist.vy = 1e-30;
	ray->delta = create_vector(fabsf(1 / ray->ray_dist.vx), \
		fabsf(1 / ray->ray_dist.vy), 0);
	ray->map_pos = create_vector(player->pos.vx, player->pos.vy, 0);
}

static void	ray_side_condition(t_ray *ray)
{
	if (!ray->side)
		ray->raydist = ray->side_dist.vx - ray->delta.vx;
	else
		ray->raydist = ray->side_dist.vy - ray->delta.vy;
}

static void	ray_algo(t_game *game, t_ray *ray)
{
	while (!ray->done)
	{
		if (ray->side_dist.vx < ray->side_dist.vy)
		{
			ray->side_dist.vx += ray->delta.vx;
			ray->map_pos.vx += ray->step.vx;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.vy += ray->delta.vy;
			ray->map_pos.vy += ray->step.vy;
			ray->side = 1;
		}
		if (game->map->map[(int)ray->map_pos.vy] \
			[(int)ray->map_pos.vx] == '1')
			ray->done = true;
	}
	ray_side_condition(ray);
}

void	do_raycast(t_game *game)
{
	t_vector3	index;

	index.vx = -1;
	while (++index.vx < WIN_WIDTH)
	{
		init_rays(game->player, game->ray, index.vx);
		ray_step(game->player, game->ray);
		game->ray->done = false;
		ray_algo(game, game->ray);
		game->ray->size_cube = WIN_HEIGHT;
		init_ray_size(game->ray);
		display_walls(game, game->ray, index);
		display_line(game, game->ray, (int)index.vx);
	}
}
