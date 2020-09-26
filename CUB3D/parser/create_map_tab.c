/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:29:50 by ttarsha           #+#    #+#             */
/*   Updated: 2020/09/15 14:48:14 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*fullfill_map_line(char *s, size_t width)
{
	char	*line;
	int		spaces;
	int		i;
	char	*tmp;
	int		len;

	spaces = 0;
	i = -1;
	len = ft_strlen(s);
	if (s[len - 1] != '1')
		exit_game(EINVAL, "Invalid map");
	if (ft_strlen(s) < width)
		spaces = width - ft_strlen(s);
	if (!(tmp = malloc(sizeof(char) * spaces + 1)))
		return (NULL);
	tmp[spaces] = '\0';
	while (++i < spaces)
		tmp[i] = ' ';
	line = ft_strjoin(s, tmp);
	free(tmp);
	return (line);
}

void	check_invalid_sym(char *map)
{
	while (*map)
	{
		if (*map == '0' || *map == ' ' || *map == '1'
			|| *map == '2' || *map == 'N' || *map == 'S'
			|| *map == 'W' || *map == 'E')
			map++;
		else
			exit_game(EINVAL, "Invalid map");
	}
}

void	create_map_arr(char **arr, int map_start, t_all *all)
{
	char	*map;
	char	*line;
	char	*tmp;
	int		map_end;

	map = ft_strdup("");
	while (arr[map_start] != NULL)
	{
		line = fullfill_map_line(arr[map_start], all->map.width);
		tmp = map;
		map = ft_strjoin(map, line);
		free(tmp);
		free(line);
		map_start++;
	}
	map_end = map_start;
	all->map.map_arr = map;
	check_invalid_sym(map);
	free_arr(arr, map_end);
}
