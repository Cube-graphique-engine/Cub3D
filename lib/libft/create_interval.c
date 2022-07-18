/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_interval.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faherrau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 12:47:23 by lduplain          #+#    #+#             */
/*   Updated: 2022/07/11 13:02:12 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_interval	create_interval(float istart, float istop)
{
	t_interval	interval;

	interval.istart = istart;
	interval.istop = istop;
	return (interval);
}
