/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_info.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:16:19 by mathismartini     #+#    #+#             */
/*   Updated: 2022/07/06 00:38:55 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	error_config_file(t_game *game)
{
	ft_putstr_errnl("Error ! configuration");
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

static char	*get_path(char *path)
{
	int		i;
	char	*new_path;

	i = 0;
	while (path[i] != '.')
		i++;
	new_path = ft_strndup(path + i,
			 ft_strlen(path) - i,
			 FALSE);
	return (new_path);
}

char	*check_path_texture(t_game *game, char *path)
{
	int		i;
	char	*new_path;

	if (!path)
		error_config_file(game);
	i = ft_strichr(path, ' ');
	while (path[i] == ' ')
		i++;
	if (i == -1)
		error_texture(CONFIG_ERROR, game);
	check_format_file_xpm(game, path + i, ".xpm");
	new_path = get_path(path);
	free(path);
	path = NULL;
	return (new_path);
}
