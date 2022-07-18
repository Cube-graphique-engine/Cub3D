/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vector_vector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faherrau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:03:30 by lduplain          #+#    #+#             */
/*   Updated: 2022/07/11 13:02:12 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector3	add_vector_vector(	\
	t_vector3 vector,			\
	t_vector3 to_add)
{
	return (add_vector_coord(vector, to_add.vx, to_add.vy, to_add.vz));
}
