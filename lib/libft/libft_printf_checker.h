/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf_checker.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 16:50:35 by lduplain          #+#    #+#             */
/*   Updated: 2022/08/24 15:07:35 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_CHECKER_H
# define LIBFT_PRINTF_CHECKER_H

/*
**	START CUSTOM INCLUDES
*/

# include "libft.h"

/*
**	END CUSTOM INCLUDES
*/

/*
**	Check if char c is a valid type usable by ft_printf.
**	./printf/checker/printf_is_valid_type.c
*/
t_bool	is_valid_type(char c);

/*
**	Check if char c is a valid flag usable by ft_printf.
**	./printf/checker/printf_is_valid_flag.c
*/
t_bool	is_valid_flag(char c);

#endif
