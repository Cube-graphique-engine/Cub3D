/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bettermlx_destroy_window.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:42:26 by mathmart          #+#    #+#             */
/*   Updated: 2022/08/24 15:07:35 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bettermlx.h"

void	*bettermlx_destroy_window(t_window **window)
{
	if (*window != NULL)
	{
		bettermlx_destroy_image(*window, &(*window)->image);
		mlx_destroy_window((*window)->mlx_ptr, (*window)->win_ptr);
		mlx_destroy_mlx((*window)->mlx_ptr);
		free(*window);
	}
	return (NULL);
}
