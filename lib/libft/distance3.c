/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:50:12 by lduplain          #+#    #+#             */
/*   Updated: 2022/07/11 13:02:11 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	distance3(float a, float b, float c)
{
	return (sqrt(distance_square3(a, b, c)));
}