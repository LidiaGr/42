/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:29:50 by ttarsha           #+#    #+#             */
/*   Updated: 2020/09/15 14:48:49 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_check_all_components(t_all *all)
{
	if (all->win.width == 0 || all->win.height == 0 \
		|| all->tex.path[0] == NULL || all->tex.path[1] == NULL \
		|| all->tex.path[2] == NULL || all->tex.path[3] == NULL \
		|| all->tex.path[4] == NULL \
		|| all->tex.flag_c == 0 || all->tex.flag_f == 0)
		exit_game(EINVAL, "Something failed");
}

int		check_content(char *s, t_all *all)
{
	int i;

	i = 0;
	if (s[i] == 'R' && s[i + 1] == ' ')
	{
		p_res(s + 2, all);
	}
	ft_tex_check(s, all);
	ft_color_check(s, all);
	if ((s[i] == '1' && s[ft_strlen(s) - 1] == '1')
		|| (s[i] == ' ' && s[ft_strlen(s) - 1] == '1'))
		return (1);
	return (0);
}

void	check_lines(char *str, t_all *all)
{
	char	**arr;
	int		i;
	int		map_start;

	i = 0;
	map_start = 0;
	arr = ft_split(str, '\n');
	free(str);
	while (arr[i] != NULL)
	{
		map_start = check_content(arr[i], all);
		if (map_start == 1)
			break ;
		i++;
	}
	ft_check_all_components(all);
	p_map(arr, i, all);
}

void	ft_parser(t_all *all, int *fd)
{
	char	*line;
	char	*str;
	char	*tmp;

	line = NULL;
	str = ft_strdup("");
	while (get_next_line(&line, *fd) != 0)
	{
		tmp = line;
		line = ft_strjoin(line, "\n");
		free(tmp);
		tmp = str;
		str = ft_strjoin(str, line);
		free(tmp);
		free(line);
	}
	tmp = str;
	str = ft_strjoin(str, line);
	free(tmp);
	free(line);
	check_lines(str, all);
	close(*fd);
}
