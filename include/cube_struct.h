/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:02:48 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/05 16:32:33 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_CUBE_STRUCT_H
#define CUBE_CUBE_STRUCT_H

# include <libft.h>
# include <bettermlx_struct.h>
# include <math.h>

typedef struct s_player
{
	size_t		pos_x;
	size_t		pos_y;
	t_vector3	pos;
	char		orientation;
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
	char	**str_map;
	char	**file;
	int		*bit_map;
	size_t	height;
	size_t	width;
	size_t	start;
	size_t	end;
    size_t  size;
}				t_map;

typedef struct s_cube_coo
{
	t_vector3 	up_left;
	t_vector3	down_left;
	t_vector3	up_right;
	t_vector3	down_right;
}				t_cube_coo;

//Main struct
typedef struct s_game
{
	t_map		*map;
	t_texture	*texture;
	t_player	*player;
	t_window	*window;
	t_cube_coo	coord;
	t_image		*n_image;
	t_image		*s_image;
	t_image		*w_image;
	t_image		*e_image;
	t_image		*d_floor;
	t_image		*d_ceiling;
	bool		debug;
}			t_game;

#endif
