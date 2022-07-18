/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 01:08:06 by mathismartini     #+#    #+#             */
/*   Updated: 2022/07/06 01:56:04 by mathismartini    ###   ########.fr       */
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
	free(game->map->file);
	free(game->texture);
	free(game->map);
	free(game);
	exit(EXIT_FAILURE);
}

static char	*get_color_value(int *index, const char *info)
{
	char	*value;
	int		i;
	int		j;

	i = *index;
	j = 0;
	value = ft_calloc(4, sizeof(char));
	while ((i < 3 || info[i] != ',') && info[i])
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

static int	get_numbers(const char *info)
{
	int	i;

	i = ft_strichr(info, ' ');
	while (info[i] == ' ')
		i++;
	return (i);
}

t_color	add_color(const char *info, t_game *game)
{
	t_color	color;
	int		i;
	int		j;
	char	**value;

	i = get_numbers(info);
	if (i <= 0)
		error_colors(game);
	value = ft_calloc(4, sizeof(char *));
	j = -1;
	while (info[i] && ++j < 3)
	{
		value[j] = get_color_value(&i, info);
		i++;
	}
	value[++j] = NULL;
	color = create_color(TRANSPARENCY, to_convert(&value[0], game), \
		to_convert(&value[1], game), to_convert(&value[2], game));
	free(value);
	value = NULL;
	return (color);
}
