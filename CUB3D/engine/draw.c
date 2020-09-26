/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:29:50 by ttarsha           #+#    #+#             */
/*   Updated: 2020/09/15 14:49:01 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	draw_ceil_floor(t_all *all)
{
	int		x;
	int		y;

	y = 0;
	while (y < all->win.height / 2)
	{
		x = 0;
		while (x < all->win.width)
		{
			all->img.addr[y * all->win.width + x] = all->tex.rgb_c;
			x++;
		}
		y++;
	}
	while (y < all->win.height)
	{
		x = 0;
		while (x < all->win.width)
		{
			all->img.addr[y * all->win.width + x] = all->tex.rgb_f;
			x++;
		}
		y++;
	}
}

t_img	*get_texture(t_all *all)
{
	if (fmod(all->ray.x, 1.0) == 0)
	{
		if (cos(all->ray.dir) > 0)
			return (&all->tex.tex[2]);
		else
			return (&all->tex.tex[3]);
	}
	else
	{
		if (sin(all->ray.dir) > 0)
			return (&all->tex.tex[0]);
		else
			return (&all->tex.tex[1]);
	}
}

int		draw_walls(t_all *all, int start_x, int start_y)
{
	int		col;
	double	tx;
	int		ty;
	t_img	*texture;

	col = -1;
	texture = get_texture(all);
	if (fmod(all->ray.x, 1.0) == 0)
		tx = fmod(all->ray.y, 1.0);
	else
		tx = fmod(all->ray.x, 1.0);
	if ((fmod(all->ray.y, 1.0) == 0 && sin(all->ray.dir) > 0) \
		|| (fmod(all->ray.x, 1.0) == 0 && cos(all->ray.dir) < 0))
		tx = 1 - tx;
	tx *= texture->width;
	while (++col < all->ray.col_h)
	{
		ty = col * texture->height / all->ray.col_h;
		all->img.addr[start_x + (start_y + col) * all->win.width] =\
		texture->addr[(int)tx + ty * texture->width];
	}
	return (1);
}

int		set_walls(int keycode, t_all *all)
{
	int i;

	i = -1;
	key_check(keycode, all);
	draw_ceil_floor(all);
	while (++i < all->win.width)
	{
		all->ray.dir = all->player.dir - all->player.fov / 2 \
						+ all->player.fov * i / (double)all->win.width;
		init_ray(all);
		all->ray.dist = hypot(all->ray.x - all->player.x,\
							all->ray.y - all->player.y);
		all->tools.depth_buffer[i] = all->ray.dist;
		all->ray.col_h = all->win.height /\
						(all->ray.dist * cos(all->ray.dir - all->player.dir));
		draw_walls(all, i, all->win.height / 2 - all->ray.col_h / 2);
	}
	sprite_to_draw(all);
	mlx_do_sync(all->mlx.ptr);
	if (all->tools.save != 1)
		mlx_put_image_to_window(all->mlx.ptr, all->win.ptr, all->img.ptr, 0, 0);
	return (1);
}
