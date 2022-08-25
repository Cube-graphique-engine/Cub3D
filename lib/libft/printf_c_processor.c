/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_c_processor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faherrau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 18:53:45 by lduplain          #+#    #+#             */
/*   Updated: 2022/08/24 15:07:35 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	c_processor(	\
	t_printable *prtbl,	\
	va_list args,		\
	char **to_print)
{
	size_t	char_count;
	int		spaces;

	(void)to_print;
	char_count = 0;
	spaces = prtbl->star_value - 1;
	if (prtbl->star && spaces > 0)
		char_count += ft_putnchar(' ', spaces);
	char_count += ft_putchar((char)va_arg(args, int));
	spaces = prtbl->minus_value - 1;
	if (prtbl->minus && spaces > 0)
		char_count += ft_putnchar(' ', spaces);
	return (char_count);
}
