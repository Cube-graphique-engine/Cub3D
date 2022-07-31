/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <mathmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:25:26 by mathmart          #+#    #+#             */
/*   Updated: 2022/07/31 23:09:12 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	display_info(t_game *game)
{
	int	i;

	printf("%s\n", game->texture->n_path);
	printf("%s\n", game->texture->s_path);
	printf("%s\n", game->texture->e_path);
	printf("%s\n", game->texture->w_path);
	i = -1;
	while (game->map->map[++i])
		printf("%s\n", game->map->map[i]);
	printf("x = %zu\ny = %zu\n", game->player->pos_x, game->player->pos_y);
	printf("orientation = %c\n", game->player->orientation);
}
