/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <mathmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:29:50 by mathmart          #+#    #+#             */
/*   Updated: 2022/07/17 17:20:14 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static char	**copy_double_tab(t_game *game, size_t index)
{
	char	**copy;
	size_t	i;

	i = 0;
	copy = ft_calloc(size_char_tab(game->map->file, index, true) + 1,
		sizeof(char *));
	while (game->map->file[index + i])
	{
		copy[i] = ft_strdup(game->map->file[index + i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	get_map(t_game *game)
{
	size_t	i;

	i = 0;
	while (game->map->file[i])
	{
		if (is_numberstr(game->map->file[i]))
		{
			game->map->map = copy_double_tab(game, i);
			if (check_base(game->map->map, "10NSEW ") == false)
				error_player(ERROR_CONFIG_MAP, game);
			get_player_position(game);
			game->map->map = copy_double_tab(game, i);
			return ;
		}
		i++;
	}
}

//void	get_map(t_game *game, char ***map)
//{
//	size_t	i;
//
//	i = 0;
//	while (game->map->file[i])
//	{
//		if (is_numberstr(game->map->file[i]))
//		{
//			*map = add_map(game, i);
//			if (check_base(*map, "10NSEW ") == false)
//				error_player(ERROR_CONFIG_MAP, game);
//			get_player_position(game);
//			return ;
//		}
//		i++;
//	}
//}