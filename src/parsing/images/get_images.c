/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:05:39 by mathismartini     #+#    #+#             */
/*   Updated: 2022/07/05 20:42:58 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	free_debug_path(t_game *game)
{
	if (game->debug == false)
		return ;
	free(game->texture->d_floor);
	free(game->texture->d_ceilling);
	game->texture->d_floor = NULL;
	game->texture->d_ceilling = NULL;
}

static void	free_images_path(t_game *game)
{
	free(game->texture->n_path);
	free(game->texture->s_path);
	free(game->texture->w_path);
	free(game->texture->e_path);
	game->texture->n_path = NULL;
	game->texture->s_path = NULL;
	game->texture->w_path = NULL;
	game->texture->e_path = NULL;
	free(game->texture);
	game->texture = NULL;
}

void	get_image_xpm(t_game *game)
{
	game->n_image = bettermlx_init_xpm_image(game->window,
			game->texture->n_path);
	game->s_image = bettermlx_init_xpm_image(game->window,
			game->texture->s_path);
	game->w_image = bettermlx_init_xpm_image(game->window,
			game->texture->w_path);
	game->e_image = bettermlx_init_xpm_image(game->window,
			game->texture->e_path);
	if (game->debug == true)
	{
		game->d_floor = bettermlx_init_xpm_image(game->window,
				game->texture->d_floor);
		game->d_ceiling = bettermlx_init_xpm_image(game->window,
				game->texture->d_ceilling);
		free_debug_path(game);
	}
	free_images_path(game);
}
