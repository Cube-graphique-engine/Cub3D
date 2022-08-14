/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:20:11 by mathmart          #+#    #+#             */
/*   Updated: 2022/08/10 14:20:13 by mathmart         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	put_player(t_game *game, t_player *player)
{
	draw_cube(16, player->pos, create_icolor(1, 255, 255, 30), game);
}