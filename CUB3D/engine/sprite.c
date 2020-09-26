/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:29:50 by ttarsha           #+#    #+#             */
/*   Updated: 2020/09/15 14:49:26 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		check_sprite_position(t_all *all, double x, double y)
{
	if (all->sprite == NULL)
		return (1);
	if (all->sprite->x == x && all->sprite->y == y)
		return (0);
	return (1);
}

void	set_sprite_position(t_all *all, double tmp_x, double tmp_y)
{
	t_sprite *sprite;

	if (check_sprite_position(all, floor(tmp_x) + 0.5, floor(tmp_y) + 0.5))
	{
		sprite = malloc(sizeof(*sprite));
		sprite->x = floor(tmp_x) + (fmod(tmp_x, 1.0) == 0 ? (-0.5) : 0.5);
		sprite->y = floor(tmp_y) + (fmod(tmp_y, 1.0) == 0 ? (-0.5) : 0.5);
		sprite->dir = atan2(sprite->y - all->player.y, \
					sprite->x - all->player.x);
		sprite->dist = hypot(sprite->x - all->player.x, \
					sprite->y - all->player.y);
		while (sprite->dir - all->player.dir > M_PI)
			sprite->dir -= 2 * M_PI;
		while (sprite->dir - all->player.dir < -M_PI)
			sprite->dir += 2 * M_PI;
		sprite->screen_size = (all->win.height / sprite->dist);
		sprite->hor_offset = (sprite->dir - all->player.dir) /\
								all->player.fov * all->win.width \
								- sprite->screen_size / 4;
		sprite->vert_offset = all->win.height / 2 - sprite->screen_size / 4;
		sprite->next = all->sprite;
		all->sprite = sprite;
	}
}

void	sprite_loop(int i, int size, int j, t_all *all)
{
	int start_x;

	start_x = all->win.width / 2;
	while (++i < all->sprite->screen_size)
	{
		if (all->sprite->hor_offset + i < -start_x || \
			all->sprite->hor_offset + i >= start_x)
			continue ;
		if (all->tools.depth_buffer[start_x + all->sprite->hor_offset + i] \
			< all->sprite->dist)
			continue ;
		while (++j < all->sprite->screen_size)
		{
			if ((unsigned int)all->tex.tex[4].addr[i * size /\
				all->sprite->screen_size \
				+ j * size / all->sprite->screen_size * all->tex.tex[4].width] \
				== 0x00000000)
				continue ;
			all->img.addr[(start_x + all->sprite->hor_offset + i) + \
			((all->sprite->vert_offset + j) * all->win.width)] = \
			all->tex.tex[4].addr[i * size / all->sprite->screen_size + j * \
			size / all->sprite->screen_size * all->tex.tex[4].width];
		}
		j = -1;
	}
}

void	draw_sprite(t_all *all)
{
	int size;
	int	i;
	int j;

	i = -1;
	j = -1;
	size = all->tex.tex[4].width / \
			(all->tex.tex[4].width / all->tex.tex[4].height);
	sprite_loop(i, size, j, all);
	free(all->sprite);
}

void	sprite_to_draw(t_all *all)
{
	t_all	*tmp;

	tmp = all;
	while (tmp->sprite != NULL)
	{
		draw_sprite(tmp);
		tmp->sprite = tmp->sprite->next;
	}
}
