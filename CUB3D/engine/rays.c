/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:29:50 by ttarsha           #+#    #+#             */
/*   Updated: 2020/09/15 14:49:16 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ray_grid(t_all *all)
{
	double	grid_x;
	double	grid_y;

	grid_x = all->ray.x - trunc(all->ray.x);
	if (cos(all->ray.dir) > 0 || grid_x == 0)
		grid_x = 1 - grid_x;
	grid_y = all->ray.y - trunc(all->ray.y);
	if (sin(all->ray.dir) > 0 || grid_y == 0)
		grid_y = 1 - grid_y;
	if (fabs(grid_x / cos(all->ray.dir)) <
		fabs(grid_y / sin(all->ray.dir)))
	{
		all->ray.x += copysign(grid_x, cos(all->ray.dir));
		all->ray.y += fabs(grid_x / cos(all->ray.dir)) * sin(all->ray.dir);
	}
	else
	{
		all->ray.y += copysign(grid_y, sin(all->ray.dir));
		all->ray.x += fabs(grid_y / sin(all->ray.dir)) * cos(all->ray.dir);
	}
}

void	init_ray(t_all *all)
{
	double	tmp_x;
	double	tmp_y;

	all->ray.x = all->player.x;
	all->ray.y = all->player.y;
	tmp_x = all->ray.x + (fmod(all->ray.x, 1.0) == 0 ? \
			copysign(0.5, cos(all->ray.dir)) : 0);
	tmp_y = all->ray.y + (fmod(all->ray.y, 1.0) == 0 ? \
			copysign(0.5, sin(all->ray.dir)) : 0);
	while (all->map.map_arr[(int)tmp_y * all->map.width + (int)tmp_x] != '1')
	{
		ray_grid(all);
		tmp_x = all->ray.x + (fmod(all->ray.x, 1.0) == 0 ? \
				copysign(0.5, cos(all->ray.dir)) : 0);
		tmp_y = all->ray.y + (fmod(all->ray.y, 1.0) == 0 ? \
				copysign(0.5, sin(all->ray.dir)) : 0);
		if (all->map.map_arr[(int)tmp_y * all->map.width + (int)tmp_x] == '2')
			set_sprite_position(all, tmp_x, tmp_y);
	}
}
