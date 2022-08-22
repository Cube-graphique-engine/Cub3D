/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_size_rays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:31:19 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/22 15:09:12 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_ray_size(t_ray *ray)
{
	ray->lineh = (int)(ray->size_cube / ray->raydist);
	ray->start = -ray->lineh * 0.5 + ray->size_cube * 0.5;
	if (ray->start < 0)
		ray->start = 0;
	ray->stop = ray->lineh * 0.5 + ray->size_cube * 0.5;
	if (ray->stop >= ray->size_cube)
		ray->stop = ray->size_cube - 1;
}
