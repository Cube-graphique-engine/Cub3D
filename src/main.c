/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:01:01 by mathismartini     #+#    #+#             */
/*   Updated: 2022/07/25 18:16:56 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac <= 1)
		ft_putstr_errnl("Error need more arguments !");
	game = init_main_struct();
	parse_map(game, av);
	return (EXIT_SUCCESS);
}

//free all
