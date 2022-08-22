/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_orientation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:26:14 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/22 14:51:47 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	get_player_info(t_player *player)
{
	player->spawn = create_vector(player->pos_x, player->pos_y, 0);
	player->pos = create_vector(player->pos_x + 0.5, player->pos_y + 0.5, 0);
}

void	init_player_orientation(t_player *player)
{
	if (player->orientation == 'N')
	{
		player->direction = create_vector(0, -1, 0);
		player->cam = create_vector(player->fov, 0, 0);
	}
	else if (player->orientation == 'S')
	{
		player->direction = create_vector(0, 1, 0);
		player->cam = create_vector(-player->fov, 0, 0);
	}
	else if (player->orientation == 'W')
	{
		player->direction = create_vector(-1, 0, 0);
		player->cam = create_vector(0, -player->fov, 0);
	}
	else if (player->orientation == 'E')
	{
		player->direction = create_vector(1, 0, 0);
		player->cam = create_vector(0, player->fov, 0);
	}
	get_player_info(player);
}
