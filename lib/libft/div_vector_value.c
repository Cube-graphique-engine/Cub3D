/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_vector_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:08:18 by lduplain          #+#    #+#             */
/*   Updated: 2022/07/11 13:02:12 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector3	div_vector_value(t_vector3 vector, float to_div)
{
	return (div_vector_coord(vector, to_div, to_div, to_div));
}
