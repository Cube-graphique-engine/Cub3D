/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathismartini <mathismartini@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:45:28 by mathismartini     #+#    #+#             */
/*   Updated: 2022/08/22 11:08:53 by mathismartini    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static t_image 	*get_dir_wall(t_game *game, t_ray *ray)
{
	if (ray->side == 0 && ray->ray_dist.vx > 0)
		return (game->e_image);
	else if (ray->side == 0 && ray->ray_dist.vx < 0)
		return (game->w_image);
	else if (ray->side == 1 && ray->ray_dist.vy > 0)
		return (game->s_image);
	else if (ray->side == 1 && ray->ray_dist.vy < 0)
		return (game->n_image);
	return (NULL);
}

static void	my_mlx_put_pixel(t_game *d, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > WIN_WIDTH - 1 || y > WIN_HEIGHT - 1)
		return ;
	dst = d->window->image->img_addr + (y * d->window->image->size_line + \
		x * (d->window->image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	get_pixel_color(t_image *img, int x, int y)
{
	int		color;
	char	*dst;

	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	dst = img->img_addr + (y * img->size_line + x * \
		(img->bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

static void	do_loop(t_ray *ray, t_vector3 i, t_game *game, t_image *image)
{
	i.vy = ray->start - 1;
	while (++i.vy < ray->stop)
	{
		ray->tex_y = (int)ray->tex_pos & (image->width - 1);
		ray->tex_pos += ray->step_wall;
		my_mlx_put_pixel(game, i.vx, i.vy, \
		get_pixel_color(image, ray->tex_x, ray->tex_y));
	}
}

void	display_walls(t_game *game, t_ray *ray, t_vector3 i)
{
	t_image	*image;

	image = get_dir_wall(game, ray);
	if (ray->side == 0)
		ray->wallx = game->player->pos.vy + ray->raydist * ray->ray_dist.vy;
	else
		ray->wallx = game->player->pos.vx + ray->raydist * ray->ray_dist.vx;
	ray->wallx -= floor(ray->wallx);
	ray->tex_x = (int)(ray->wallx * (double)image->width);
	if (ray->side == 0 && ray->ray_dist.vx > 0)
		ray->tex_x = image->width - ray->tex_x - 1;
	if (ray->side == 1 && ray->ray_dist.vy < 0)
		ray->tex_x = image->width - ray->tex_x - 1;
	ray->step_wall = 1.0 * image->width / ray->lineh;
	ray->tex_pos = (ray->start - WIN_HEIGHT * 0.5 + ray->lineh * 0.5) \
		* ray->step_wall;
	do_loop(ray, i, game, image);
}
