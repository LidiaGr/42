/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:29:50 by ttarsha           #+#    #+#             */
/*   Updated: 2020/09/15 14:49:08 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	init_tex(t_all *all)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		if (!(all->tex.tex[i].ptr = mlx_xpm_file_to_image(all->mlx.ptr,\
			all->tex.path[i], &all->tex.tex[i].width, &all->tex.tex[i].height)))
			exit_game(EINVAL, "Textures");
		if (!(all->tex.tex[i].addr = (int *)mlx_get_data_addr(\
			all->tex.tex[i].ptr, &all->tex.tex[i].bits_per_pixel, \
			&all->tex.tex[i].line_length, &all->tex.tex[i].endian)))
			exit_game(EINVAL, "Textures");
	}
	all->tex.tex[i].ptr = NULL;
}

void	init_picture(t_all *all)
{
	all->mlx.ptr = mlx_init();
	if (all->tools.save != 1)
		all->win.ptr = mlx_new_window(all->mlx.ptr, all->win.width, \
						all->win.height, "ttarsha");
	all->img.ptr = mlx_new_image(all->mlx.ptr, all->win.width, \
					all->win.height);
	all->img.addr = (int *)mlx_get_data_addr(all->img.ptr, \
					&all->img.bits_per_pixel, \
					&all->img.line_length, &all->img.endian);
	all->ray.x = all->player.x;
	all->ray.y = all->player.y;
	all->ray.dist = 0;
	all->ray.col_h = 0;
	all->sprite = NULL;
	init_tex(all);
	if (all->tools.save == 1)
		ft_save_to_bmp(all);
}

void	init_pre(t_all *all)
{
	all->win.width = 0;
	all->win.height = 0;
	all->map.width = -1;
	all->map.height = -1;
	all->map.map_arr = NULL;
	all->player.dir = -1;
	all->player.x = -1;
	all->player.y = -1;
	all->tex.path[0] = NULL;
	all->tex.path[1] = NULL;
	all->tex.path[2] = NULL;
	all->tex.path[3] = NULL;
	all->tex.path[4] = NULL;
	all->tex.path[5] = NULL;
	all->tex.flag_c = 0;
	all->tex.flag_f = 0;
}
