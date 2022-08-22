/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 22:03:17 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/21 23:19:18 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	rotate_left(t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->direction.vx;
	player->direction.vx = player->direction.vx * cos(-player->sensi) \
	- player->direction.vy * sin(-player->sensi);
	player->direction.vy = old_dir_x * sin(-player->sensi) \
	+ player->direction.vy * cos(-player->sensi);
	old_plane_x = player->cam.vx;
	player->cam.vx = player->cam.vx * cos(-player->sensi) \
	- player->cam.vy * sin(-player->sensi);
	player->cam.vy = old_plane_x * sin(-player->sensi) \
	+ player->cam.vy * cos(-player->sensi);
}

void	rotate_right(t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->direction.vx;
	player->direction.vx = player->direction.vx * cos(player->sensi) \
	- player->direction.vy * sin(player->sensi);
	player->direction.vy = old_dir_x * sin(player->sensi) \
	+ player->direction.vy * cos(player->sensi);
	old_plane_x = player->cam.vx;
	player->cam.vx = player->cam.vx * cos(player->sensi) \
	- player->cam.vy * sin(player->sensi);
	player->cam.vy = old_plane_x * sin(player->sensi) \
	+ player->cam.vy * cos(player->sensi);
}
