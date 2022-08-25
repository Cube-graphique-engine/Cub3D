/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 01:08:06 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/24 19:36:43 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	error_colors(t_game *game)
{
	ft_putstr_errnl("Error ! Incorrect configuration information");
	free(game->texture->n_path);
	free(game->texture->s_path);
	free(game->texture->w_path);
	free(game->texture->e_path);
	if (game->debug)
	{
		free(game->texture->d_ceilling);
		free(game->texture->d_floor);
	}
	free(game->texture);
	ft_destroy_string_array(&game->map->map);
	ft_destroy_string_array(&game->map->str_map);
	free(game->map);
	free(game->player);
	free(game);
	game = NULL;
	exit(EXIT_FAILURE);
}

static char	*get_color_value(int *index, const char *info)
{
	char	*value;
	int		i;
	int		j;

	i = *index;
	j = 0;
	value = ft_calloc(4, sizeof(char *));
	while ((i < 3 || info[i] != ',') && info[i] && j < 4)
	{
		value[j] = info[i];
		i++;
		j++;
	}
	value[j] = '\0';
	*index = i;
	return (value);
}

static unsigned char	to_convert(char **value, t_game *game)
{
	int	convert;

	if (!is_numberstr(*value))
		error_colors(game);
	convert = ft_atoi(*value);
	if (!(convert >= 0 && convert <= 255))
		error_colors(game);
	free(*value);
	*value = NULL;
	return ((unsigned char)convert);
}

static int	get_numbers(const char *info, t_game *game)
{
	int	i;

	i = ft_strichr(info, ' ');
	while (info[i] == ' ')
		i++;
	check_info(info, i, game);
	check_numbers(info, game);
	return (i);
}

t_color	add_color(const char *info, t_game *game)
{
	t_color	color;
	int		i;
	int		j;
	char	**value;

	i = get_numbers(info, game);
	if (i <= 0)
		error_colors(game);
	value = ft_calloc(4, sizeof(char *));
	j = -1;
	while (info[i] && ++j < 3)
	{
		value[j] = get_color_value(&i, info);
		if (j == 2)
			break ;
		i++;
	}
	value[3] = NULL;
	color = create_color(TRANSPARENCY, to_convert(&value[0], game), \
		to_convert(&value[1], game), to_convert(&value[2], game));
	free(value);
	value = NULL;
	return (color);
}
