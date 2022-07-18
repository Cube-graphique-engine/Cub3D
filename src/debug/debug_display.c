/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <mathmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:25:26 by mathmart          #+#    #+#             */
/*   Updated: 2022/07/11 09:25:26 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	display_info(t_game *game)
{
	printf("%s\n", game->texture->n_path);
	printf("%s\n", game->texture->s_path);
	printf("%s\n", game->texture->e_path);
	printf("%s\n", game->texture->w_path);
}