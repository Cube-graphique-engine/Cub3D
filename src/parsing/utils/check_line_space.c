/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 01:59:34 by mathismartini     #+#    #+#             */
/*   Updated: 2022/07/31 21:53:24 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

size_t	check_empty_line(char **line, size_t index)
{
	while (index > 0)
	{
		if (line[index] && (int)line[index][0] != 0)
			return (index);
		index--;
	}
	return (index);
}

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
