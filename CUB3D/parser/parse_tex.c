/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:29:50 by ttarsha           #+#    #+#             */
/*   Updated: 2020/09/15 14:48:44 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*p_texture(char *s)
{
	char	*path;
	char	*tmp;
	int		i;

	i = 0;
	if (s[i] == 'S' && s[i + 1] == ' ')
		s += 2;
	else
		s += 3;
	tmp = ft_strtrim(s, " ");
	path = ft_strdup(tmp);
	free(tmp);
	return (path);
}

void	ft_tex_check_next(char *s, t_all *all)
{
	int i;

	i = 0;
	if (s[i] == 'E' && s[i + 1] == 'A' && s[i + 2] == ' ')
	{
		if (all->tex.path[3] == NULL)
			all->tex.path[3] = p_texture(s);
		else
			exit_game(EINVAL, "Duplicate texture in the Map");
	}
	else if (s[i] == 'S' && s[i + 1] == ' ')
	{
		if (all->tex.path[4] == NULL)
			all->tex.path[4] = p_texture(s);
		else
			exit_game(EINVAL, "Duplicate sprite texture in the Map");
	}
}

void	ft_tex_check(char *s, t_all *all)
{
	int i;

	i = 0;
	if (s[i] == 'N' && s[i + 1] == 'O' && s[i + 2] == ' ')
	{
		if (all->tex.path[0] == NULL)
			all->tex.path[0] = p_texture(s);
		else
			exit_game(EINVAL, "Duplicate texture in the Map");
	}
	else if (s[i] == 'S' && s[i + 1] == 'O' && s[i + 2] == ' ')
	{
		if (all->tex.path[1] == NULL)
			all->tex.path[1] = p_texture(s);
		else
			exit_game(EINVAL, "Duplicate texture in the Map");
	}
	else if (s[i] == 'W' && s[i + 1] == 'E' && s[i + 2] == ' ')
	{
		if (all->tex.path[2] == NULL)
			all->tex.path[2] = p_texture(s);
		else
			exit_game(EINVAL, "Duplicate texture in the Map");
	}
	ft_tex_check_next(s, all);
}
