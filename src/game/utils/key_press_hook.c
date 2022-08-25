/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:26:19 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/24 15:07:36 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	key_press_hook(int key_code, t_game *game)
{
	game->window->keyboard[key_code] = true;
	return (0);
}

int	key_release_hook(int key_code, t_game *game)
{
	game->window->keyboard[key_code] = false;
	return (0);
}
