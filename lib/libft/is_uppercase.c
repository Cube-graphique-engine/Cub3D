/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_uppercase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faherrau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:41:26 by lduplain          #+#    #+#             */
/*   Updated: 2022/08/24 15:07:34 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	is_uppercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (TRUE);
	return (FALSE);
}
