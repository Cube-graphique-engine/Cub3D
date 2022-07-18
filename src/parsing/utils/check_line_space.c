/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 01:59:34 by mathismartini     #+#    #+#             */
/*   Updated: 2022/07/25 18:54:44 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool	check_line_space(const char *map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}
