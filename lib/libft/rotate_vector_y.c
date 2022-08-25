/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_vector_y.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:18:54 by lduplain          #+#    #+#             */
/*   Updated: 2022/08/24 15:07:34 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector3	rotate_vector_y(t_vector3 vector, double angle)
{
	float	vx;
	float	vz;

	vx = cos(angle) * vector.vx - sin(angle) * vector.vz;
	vz = -sin(angle) * vector.vx - cos(angle) * vector.vz;
	return (create_vector(vx, vector.vz, vz));
}
