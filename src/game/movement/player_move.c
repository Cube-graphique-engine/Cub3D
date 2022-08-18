/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:26:02 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/18 22:03:11 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static float	get_vy(t_window *window)
{
	float	vy;

	vy = -(window->keyboard[KEY_S] && !window->keyboard[KEY_W]) + \
		(window->keyboard[KEY_W] && !window->keyboard[KEY_S]);
	return (vy);
}

static float	get_vx(t_window *window)
{
	float	vx;

	vx = -(window->keyboard[KEY_D] && !window->keyboard[KEY_A]) + \
		(window->keyboard[KEY_A] && !window->keyboard[KEY_D]);
	return (vx);
}

static void	pos_player(t_game *game, t_vector3 pred)
{
	if (game->map->str_map[(int)pred.vy][(int)pred.vx] == '0')
		game->player->pos.vy = pred.vy;
	if (game->map->str_map[(int)pred.vy][(int)pred.vx] == '0')
		game->player->pos.vx = pred.vx;
}

void	player_move(t_game *game, t_window *window)
{
	t_vector3 	pred;
	t_vector3	dir;
	double		angle;

	dir.vy = get_vy(window);
	dir.vx = get_vx(window);
	if (!dir. vx && !dir.vy)
		return ;
	angle = atan2(dir.vy, dir.vx);
	pred.vx = game->player->pos.vx + (dir.vx != 0) \
	* ((game->player->cam.vx * game->player->speed) * -cos(angle));
	pred.vy = game->player->pos.vy + (dir.vx != 0) \
	* ((game->player->cam.vy * game->player->speed) * -cos(angle));
	pred.vx += (dir.vy != 0) * ((game->player->direction.vx * \
		game->player->speed) * sin(angle));
	pred.vy += (dir.vy != 0) * ((game->player->direction.vy * \
		game->player->speed) * sin(angle));
	pos_player(game, pred);
}
