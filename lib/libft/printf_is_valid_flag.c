/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 16:52:57 by lduplain          #+#    #+#             */
/*   Updated: 2022/08/24 15:07:35 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	is_valid_flag(char c)
{
	if (c == '-'
		|| c == '*'
		|| c == '.'
		|| c == '0')
		return (TRUE);
	return (FALSE);
}
