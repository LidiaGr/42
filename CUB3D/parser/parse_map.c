/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:29:50 by ttarsha           #+#    #+#             */
/*   Updated: 2020/09/15 14:48:33 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		check_walls(size_t x, size_t y, char **map, size_t lines)
{
	if ((x > ft_strlen(map[y]) - 1) || map[y][x] == ' ')
		return (0);
	if (map[y][x] == '1')
		return (1);
	else if (y == 0 || y == lines - 1 \
			|| x == 0 || x == ft_strlen(map[y]) - 1)
		return (0);
	if (map[y][x] == '3')
		return (1);
	map[y][x] = '3';
	if (!(check_walls(x + 1, y, map, lines)))
		return (0);
	if (!(check_walls(x - 1, y, map, lines)))
		return (0);
	if (!(check_walls(x, y + 1, map, lines)))
		return (0);
	if (!(check_walls(x, y - 1, map, lines)))
		return (0);
	map[y][x] = '1';
	return (1);
}

void	check_map(char **arr, int i, t_all *all)
{
	char	**only_map;
	size_t	lines;

	lines = 0;
	only_map = ft_calloc(sizeof(char *), all->map.height + 1);
	while (arr[i])
	{
		only_map[lines] = ft_strdup(arr[i]);
		lines++;
		i++;
	}
	only_map[lines] = NULL;
	if (!(check_walls(all->player.x, all->player.y, only_map, lines)))
		exit_game(EINVAL, "Invalid map");
	free_arr(only_map, lines);
}

void	p_map(char **arr, int map_start, t_all *all)
{
	size_t	width;
	int		height;
	int		i;

	width = 0;
	height = 0;
	i = map_start;
	while (arr[i] != NULL)
	{
		if (ft_strlen(arr[i]) > width)
			width = ft_strlen(arr[i]);
		height++;
		i++;
	}
	all->map.width = width;
	all->map.height = height;
	find_player(arr, map_start, all);
	check_map(arr, map_start, all);
	create_map_arr(arr, map_start, all);
}
