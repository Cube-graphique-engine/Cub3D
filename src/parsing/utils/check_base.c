/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:13:39 by mathismartini     #+#    #+#             */
/*   Updated: 2022/07/15 16:46:25 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static bool	is_in_base(char c, const char *base)
{
	size_t	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (true);
		i++;
	}
	return (false);
}

bool	check_base(char **strs, const char *base)
{
	size_t	j;
	size_t	i;

	i = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (is_in_base(strs[i][j], base) == false)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}