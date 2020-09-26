/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:29:50 by ttarsha           #+#    #+#             */
/*   Updated: 2020/09/15 14:49:04 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	exit_game(int error, char *str)
{
	if (error > 0)
	{
		write(1, "Error\n", 6);
		errno = error;
		perror(str);
	}
	exit(0);
}

int		close_win(t_all *all)
{
	mlx_destroy_window(all->mlx.ptr, all->win.ptr);
	exit_game(0, "");
	return (0);
}

double	check_dir(int keycode)
{
	double dir;

	if (keycode == W)
		dir = 0;
	if (keycode == S)
		dir = M_PI * (-1);
	if (keycode == A)
		dir = M_PI / 2 * (-1);
	if (keycode == D)
		dir = M_PI / 2;
	return (dir);
}

void	move_player(int keycode, t_all *all)
{
	double new_x;
	double new_y;
	double dir;

	dir = check_dir(keycode);
	new_x = all->player.x + (cos(all->player.dir + dir) * 0.1);
	new_y = all->player.y + (sin(all->player.dir + dir) * 0.1);
	if (all->map.map_arr[(int)(new_x + 0.4) + \
		(int)(new_y + 0.4) * all->map.width] != '1' \
		&& all->map.map_arr[(int)(new_x - 0.4) + \
		(int)(new_y - 0.4) * all->map.width] != '1' \
		&& all->map.map_arr[(int)(new_x - 0.4) + \
		(int)(new_y + 0.4) * all->map.width] != '1' \
		&& all->map.map_arr[(int)(new_x + 0.4) + \
		(int)(new_y - 0.4) * all->map.width] != '1')
	{
		all->player.x = new_x;
		all->player.y = new_y;
	}
}

void	key_check(int key, t_all *all)
{
	if (key == ESC)
		close_win(all);
	if (key == LEFT)
	{
		all->player.dir -= 0.1;
		if (all->player.dir <= 0)
			all->player.dir = M_PI * 2;
	}
	if (key == RIGHT)
	{
		all->player.dir += 0.1;
		if (all->player.dir >= M_PI * 2)
			all->player.dir = 0;
	}
	if (key == W || key == S || key == A || key == D)
		move_player(key, all);
}
