/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:14:10 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/24 15:07:35 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static t_player	*init_player(void)
{
	t_player	*player;

	player = ft_calloc(1, sizeof(t_player));
	if (!player)
		return (NULL);
	player->pos_x = 0;
	player->pos_y = 0;
	player->pos.vy = 0;
	player->pos.vx = 0;
	player->pos.vz = 0;
	player->orientation = 'm';
	return (player);
}

static t_texture	*init_texture_struct(void)
{
	t_texture	*texture;

	texture = ft_calloc(1, sizeof(t_texture));
	if (!texture)
		return (NULL);
	texture->n_path = NULL;
	texture->s_path = NULL;
	texture->e_path = NULL;
	texture->w_path = NULL;
	texture->d_floor = NULL;
	texture->d_ceilling = NULL;
	return (texture);
}

static t_map	*init_map_struct(void)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = NULL;
	map->str_map = NULL;
	map->file = NULL;
	map->start = 0;
	map->end = 0;
	map->height = 0;
	map->width = 0;
	map->size = 0;
	return (map);
}

t_game	*init_main_struct(void)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = init_map_struct();
	game->texture = init_texture_struct();
	game->player = init_player();
	game->n_image = NULL;
	game->s_image = NULL;
	game->w_image = NULL;
	game->e_image = NULL;
	game->d_floor = NULL;
	game->d_ceiling = NULL;
	game->debug = false;
	return (game);
}
