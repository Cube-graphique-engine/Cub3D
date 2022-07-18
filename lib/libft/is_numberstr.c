/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_numberstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:24:52 by lduplain          #+#    #+#             */
/*   Updated: 2022/07/11 13:02:11 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	is_numberstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	if (i == ft_strlen(str))
		return (FALSE);
	while (str[i])
	{
		if (!is_numeric(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
