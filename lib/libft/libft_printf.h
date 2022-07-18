/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:33:56 by lduplain          #+#    #+#             */
/*   Updated: 2022/07/11 13:02:11 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

/*
**	START CUSTOM INCLUDES
*/

# include "libft.h"
# include "libft_printf_printable.h"
# include "libft_printf_processor.h"
# include "libft_printf_checker.h"
# include "libft_printf_parser.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	Print messages like printf function. (contained in libc)
**	./printf/ft_printf.c
*/
int		ft_printf(const char *format, ...);

#endif
