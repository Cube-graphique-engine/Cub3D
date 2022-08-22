/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:02:48 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/21 23:19:17 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_STRUCT_H
# define CUBE_STRUCT_H

# include <libft.h>
# include <bettermlx_struct.h>
# include <math.h>

typedef struct s_vect2i
{
	int	x;
	int	y;
}				t_vect2i;

typedef struct s_vect2f
{
	float	x;
	float	y;
}				t_vect2f;

typedef struct s_ray
{
	t_vector3	ray_dist;
	t_vector3	delta;
	t_vector3	side_dist;
	t_vector3	map_pos;
	t_vector3	step;
	double		wallx;
	double		tex_pos;
	double		step_wall;
	float		screenx;
	float		raydist;
	int			tex_x;
	int			tex_y;
	int			side;
	int			lineh;
	int			size_cube;
	int			start;
	int			stop;
	bool		done;
}				t_ray;

typedef struct s_player
{
	size_t		pos_x;
	size_t		pos_y;
	t_vector3	pos;
	t_vector3	cam;
	t_vector3	direction;
	t_vector3	spawn;
	float		fov;
	float		sensi;
	float		speed;
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
	t_color	floor;
	t_color	ceiling;
}				t_texture;

typedef struct s_map
{
	char	**map;
	char	**str_map;
	char	**file;
	size_t	height;
	size_t	width;
	size_t	start;
	size_t	end;
	size_t	size;
}				t_map;

//Main struct
typedef struct s_game
{
	t_map		*map;
	t_texture	*texture;
	t_player	*player;
	t_ray		*ray;
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
