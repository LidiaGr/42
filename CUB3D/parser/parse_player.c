/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:29:50 by ttarsha           #+#    #+#             */
/*   Updated: 2020/09/14 16:05:42 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	set_player(t_all *all, char dir, int x, int y)
{
	if (dir == 'N')
		all->player.dir = 3 * M_PI / 2;
	if (dir == 'S')
		all->player.dir = M_PI / 2;
	if (dir == 'W')
		all->player.dir = M_PI;
	if (dir == 'E')
		all->player.dir = 2 * M_PI;
	if (all->player.x != -1 || all->player.y != -1)
		exit_game(EINVAL, "Not one player");
	all->player.x = x + 1 - 0.5;
	all->player.y = y + 1 - 0.5;
	all->player.fov = M_PI / 4;
}

void	find_player(char **arr, int map_start, t_all *all)
{
	int		i;
	int		j;
	int		y;

	i = map_start - 1;
	j = -1;
	y = 0;
	while (arr[++i])
	{
		while (arr[i][++j])
		{
			if (arr[i][j] == 'N'
				|| arr[i][j] == 'S'
				|| arr[i][j] == 'W'
				|| arr[i][j] == 'E')
				set_player(all, arr[i][j], j, y);
		}
		j = 0;
		y++;
	}
	if (all->player.x <= 0 || all->player.y <= 0)
		exit_game(EINVAL, "No player");
}
