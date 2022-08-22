/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_by_step.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:08:09 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/22 15:56:58 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	step_x(t_player *player, t_ray *ray)
{
	if (ray->ray_dist.vx < 0)
	{
		ray->step.vx = -1;
		ray->side_dist.vx = ray->delta.vx * fmodf(player->pos.vx, 1.0f);
	}
	else
	{
		ray->step.vx = 1;
		ray->side_dist.vx = (1 - fmodf(player->pos.vx, 1.0f)) * ray->delta.vx;
	}
}

static void	step_y(t_player *player, t_ray *ray)
{
	if (ray->ray_dist.vy < 0)
	{
		ray->step.vy = -1;
		ray->side_dist.vy = fmodf(player->pos.vy, 1.0f) * ray->delta.vy;
	}
	else
	{
		ray->step.vy = 1;
		ray->side_dist.vy = (1 - fmodf(player->pos.vy, 1.0f)) * ray->delta.vy;
	}
}

void	ray_step(t_player *player, t_ray *ray)
{
	step_x(player, ray);
	step_y(player, ray);
}
