/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:48:36 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/01 16:53:33 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	destroy_game(t_game *game)
{
	if (game != NULL)
	{
		bettermlx_destroy_image(game->window, &game->n_image);
		bettermlx_destroy_image(game->window, &game->s_image);
		bettermlx_destroy_image(game->window, &game->e_image);
		bettermlx_destroy_image(game->window, &game->w_image);
		if (game->debug)
		{
			bettermlx_destroy_image(game->window, &game->d_ceiling);
			bettermlx_destroy_image(game->window, &game->d_floor);
		}
		bettermlx_destroy_window(&game->window);
	}
}
