/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_string_array_size.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:33:04 by lduplain          #+#    #+#             */
/*   Updated: 2022/07/11 13:02:13 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_get_string_array_length(char **string_array)
{
	size_t	array_length;

	array_length = 0;
	if (string_array == NULL)
		return (array_length);
	while (string_array[array_length] != NULL)
		array_length++;
	return (array_length);
}
