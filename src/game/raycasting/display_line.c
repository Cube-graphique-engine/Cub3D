/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:29:38 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/24 15:07:36 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	display_line(t_game *game, t_ray *ray, int x)
{
	int	i;

	i = -1;
	while (++i < ray->start)
		bettermlx_pixel_put(game->window, create_vector(x, i, 0), \
			game->texture->ceiling, 1);
	while (i < ray->stop)
		i++;
	while (i < WIN_HEIGHT - HUD)
	{
		bettermlx_pixel_put(game->window, create_vector(x, i, 0), \
			game->texture->floor, 1);
		i++;
	}
}
