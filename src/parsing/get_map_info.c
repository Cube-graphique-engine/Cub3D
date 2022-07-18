/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:51:36 by mathismartini     #+#    #+#             */
/*   Updated: 2022/07/11 13:02:13 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	get_info(t_game *game, char *tofind, char **texture)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (game->map->file[i])
	{
		j = 0;
		while (game->map->file[i][j])
		{
			if (ft_strncmp(game->map->file[i], tofind, ft_strlen(tofind)) == 0)
			{
				*texture = ft_strdup(game->map->file[i]);
				i++;
			}
			j++;
		}
		i++;
	}
}

static bool	check_debug(t_game *game)
{
	size_t	i;

	i = 0;
	while (game->map->file[i])
	{
		if (ft_strncmp(game->map->file[i], "D", 1) == 0)
			return (true);
		i++;
	}
	return (false);
}

static void	get_colors(t_game *game, char *to_find, t_color *color)
{
	size_t	i;

	i = 0;
	while (game->map->file[i] && game->debug == false)
	{
		if (ft_strncmp(game->map->file[i], to_find, ft_strlen(to_find)) == 0)
		{
			*color = add_color(game->map->file[i], game);
			i++;
		}
		i++;
	}
}

static void	check_image_path(t_game *game)
{
	game->texture->n_path = check_path_texture(game, game->texture->n_path);
	game->texture->s_path = check_path_texture(game, game->texture->s_path);
	game->texture->e_path = check_path_texture(game, game->texture->e_path);
	game->texture->w_path = check_path_texture(game, game->texture->w_path);
	if (game->debug == true)
	{
		game->texture->d_floor = check_path_texture(game,
				game->texture->d_floor);
		game->texture->d_ceilling = check_path_texture(game,
				game->texture->d_ceilling);
	}
}

void	get_map_info(t_game *game)
{
	get_info(game, "NO", &game->texture->n_path);
	get_info(game, "SO", &game->texture->s_path);
	get_info(game, "WE", &game->texture->w_path);
	get_info(game, "EA", &game->texture->e_path);
	game->debug = check_debug(game);
	if (game->debug == false)
	{
		get_colors(game, "F", &game->texture->floor);
		get_colors(game, "C", &game->texture->ceiling);
	}
	else if (game->debug == true)
	{
		get_info(game, "F", &game->texture->d_floor);
		get_info(game, "C", &game->texture->d_ceilling);
	}
	check_image_path(game);
//	get_image_xpm(game);
}
