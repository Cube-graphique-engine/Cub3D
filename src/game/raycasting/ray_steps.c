/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_by_step.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:08:09 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/15 21:37:13 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	step_x(t_player *player, t_ray *ray)
{
	if (ray->ray_dist.vx < 0)
	{
		ray->step.vx = -1;
		ray->side_dist.vx = (player->pos.vx - ray->map_pos.vx) * \
			ray->delta.vx;
	}
	else
	{
		ray->step.vx = 1;
		ray->side_dist.vx = (ray->map_pos.vx + 1 - player->pos.vx) * \
			ray->delta.vx;
	}
}

static void	step_y(t_player *player, t_ray *ray)
{
	if (ray->ray_dist.vy < 0)
	{
		ray->step.vy = -1;
		ray->side_dist.vy = (player->pos.vy - ray->map_pos.vy) * \
			ray->delta.vy;
	}
	else
	{
		ray->step.vy = 1;
		ray->side_dist.vy = (ray->map_pos.vy + 1 - player->pos.vy) * \
			ray->delta.vy;
	}
}

void	ray_step(t_player *player, t_ray *ray)
{
	step_x(player, ray);
	step_y(player, ray);
}
