/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_init_window.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:42:38 by mathmart          #+#    #+#             */
/*   Updated: 2022/08/24 15:07:35 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bettermlx.h"

t_window	*bettermlx_init_window(
	char *title,
	int width,
	int height,
	int divider)
{
	t_window	*window;

	window = ft_calloc(1, sizeof(t_window));
	if (window == NULL)
		return (NULL);
	window->title = title;
	window->width = width;
	window->height = height;
	window->real_width = width / divider;
	window->real_height = height / divider;
	window->divider = divider;
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr, width, height, title);
	window->image = bettermlx_init_image(window, window->width, window->height);
	return (window);
}
