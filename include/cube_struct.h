/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:02:48 by mathismartini     #+#    #+#             */
/*   Updated: 2022/07/05 01:40:04 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_CUBE_STRUCT_H
#define CUBE_CUBE_STRUCT_H

# include <libft.h>
# include <bettermlx_struct.h>

typedef struct s_player
{
	size_t	pos_x;
	size_t	pos_y;
	char	orientation;
}				t_player;

typedef struct s_texture
{
	char	*n_path;
	char	*s_path;
	char	*e_path;
	char	*w_path;
	char	*d_floor;
	char	*d_ceilling;
	t_color floor;
	t_color ceiling;
}				t_texture;

typedef struct s_map
{
	char	**map;
	char	**file;
	char	*path;
	size_t	start;
}				t_map;

//Main struct
typedef struct s_game
{
	t_map		*map;
	t_texture	*texture;
	t_player	*player;
	t_window	*window;
	t_image		*n_image;
	t_image		*s_image;
	t_image		*w_image;
	t_image		*e_image;
	t_image		*d_floor;
	t_image		*d_ceiling;
	bool		debug;
}			t_game;

#endif
