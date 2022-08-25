/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:16:35 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/24 15:07:36 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool	is_validate_map(t_map *map, int x, int y)
{
	if (x < 0 || x >= (int)map->width)
		return (false);
	if (y < 0 || y >= (int)map->height)
		return (false);
	if (map->map[y][x] == ' ')
		return (false);
	if (map->map[y][x] == '1' || map->map[y][x] == -1)
		return (true);
	map->map[y][x] = -1;
	if (!is_validate_map(map, x + 1, y))
		return (false);
	if (!is_validate_map(map, x - 1, y))
		return (false);
	if (!is_validate_map(map, x, y + 1))
		return (false);
	if (!is_validate_map(map, x, y - 1))
		return (false);
	return (true);
}
