/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <mathmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:25:26 by mathmart          #+#    #+#             */
/*   Updated: 2022/08/01 00:02:20 by mathismartini    ###   ########.fr       */
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
	printf("start = %zu\nend = %zu\n", game->map->start, game->map->end);
	printf("\033[1;32mheight = %zu\nwitdh = %zu\033[0m\n", game->map->height,
		   game->map->width);
	i = -1;
	printf("MAP = \n");
	while (game->map->map[++i])
		printf("%s\n", game->map->map[i]);
	i = -1;
	printf("STR_MAP = \n");
	while (game->map->str_map[++i])
		printf("%s\n", game->map->str_map[i]);
	printf("x = %zu\ny = %zu\n", game->player->pos_x, game->player->pos_y);
	printf("orientation = %c\n", game->player->orientation);
}
