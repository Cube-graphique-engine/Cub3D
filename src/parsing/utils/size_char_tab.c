/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_char_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <mathmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:23:30 by mathmart          #+#    #+#             */
/*   Updated: 2022/07/11 10:42:39 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

size_t	size_char_tab(char **tab, size_t index, bool value)
{
	size_t	start;
	size_t	size;

	start = 0;
	size = 0;
	if (value == true)
		start = index;
	while (tab[start + size])
		size++;
	return (size);
}