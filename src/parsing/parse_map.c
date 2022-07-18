/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:51:42 by mathismartini     #+#    #+#             */
/*   Updated: 2022/07/15 18:45:28 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	size_read(char *path)
{
	int		count;
	int		fd;
	char	buf[2];

	count = 0;
	fd = open(path, O_RDONLY);
	if (!fd)
		return (0);
	while (read(fd, buf, 1))
		count++;
	close(fd);
	return (count);
}

static char	*read_file(char *path)
{
	char	*buff;
	int		fd;

	buff = ft_calloc(ft_strlen(path) + 1, sizeof(char));
	if (!buff)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (!fd)
		return (NULL);
	read(fd, buff, size_read(path));
	buff[size_read(path)] = '\0';
	close(fd);
	return (buff);
}

static void	display_info(t_game *game)
{
	printf("INFO:\n");
	for (int i = 0; game->map->map[i]; i++)
		printf("%s\n", game->map->map[i]);
//	printf("x = %zu\n", game->player->pos_x);
//	printf("y = %zu\n", game->player->pos_y);
//	printf("orientation = %c\n", game->player->orientation);
}

void	parse_map(t_game *game, char **av)
{
	char	*file;

	check_format_file_cub(game, av[1], ".cub");
	file = read_file(av[1]);
	game->map->file = ft_split(file, "\n");
//	get_map_info(game);
	get_map(game);
	display_info(game);
	free(file);
	file = NULL;
}
