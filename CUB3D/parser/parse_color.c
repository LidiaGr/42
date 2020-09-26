/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:29:50 by ttarsha           #+#    #+#             */
/*   Updated: 2020/09/15 14:48:30 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void			ft_declare_colors(int *r, int *g, int *b)
{
	*r = -1;
	*g = -1;
	*b = -1;
}

unsigned int	p_color(char *s)
{
	int				r;
	int				g;
	int				b;
	int				i;
	unsigned int	color;

	i = 0;
	ft_declare_colors(&r, &g, &b);
	while (s[i] == ' ')
		i++;
	if (ft_isdigit(s[i]))
		r = ft_atoi(s + i);
	i += num_len_base(r, 10);
	if (s[i] == ',' && ft_isdigit(*(s + i + 1)))
		g = ft_atoi(s + i + 1);
	i += num_len_base(g, 10) + 1;
	if (s[i] == ',' && ft_isdigit(*(s + i + 1)))
		b = ft_atoi(s + i + 1);
	i += num_len_base(b, 10) + 1;
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255)
		|| (ft_check_tail(s + i) == 1))
		exit_game(EINVAL, "Color");
	color = r * 256 * 256 + g * 256 + b;
	return (color);
}

void			ft_color_check(char *s, t_all *all)
{
	int i;

	i = 0;
	if (s[i] == 'C' && s[i + 1] == ' ')
	{
		if (all->tex.flag_c == 0)
		{
			all->tex.rgb_c = p_color(s + 2);
			all->tex.flag_c = 1;
		}
		else
			exit_game(EINVAL, "Duplicate color in the Map");
	}
	else if (s[i] == 'F' && s[i + 1] == ' ')
	{
		if (all->tex.flag_f == 0)
		{
			all->tex.rgb_f = p_color(s + 2);
			all->tex.flag_f = 1;
		}
		else
			exit_game(EINVAL, "Duplicate color in the Map");
	}
}
