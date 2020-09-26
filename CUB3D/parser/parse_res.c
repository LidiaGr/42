/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:29:50 by ttarsha           #+#    #+#             */
/*   Updated: 2020/09/15 14:48:40 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	p_res(char *s, t_all *all)
{
	if (all->win.width != 0 || all->win.height != 0)
		exit_game(EINVAL, "Duplicate Resolution");
	while (*s == ' ')
		s++;
	all->win.width = ft_atoi(s);
	s += num_len_base(all->win.width, 10);
	while (*s == ' ')
		s++;
	all->win.height = ft_atoi(s);
	s += num_len_base(all->win.height, 10);
	if (all->win.width > 1920)
		all->win.width = 1920;
	if (all->win.height > 1080)
		all->win.height = 1080;
	if (all->win.width <= 0 || all->win.height <= 0 || (ft_check_tail(s) == 1))
		exit_game(EINVAL, "Wrong resolution");
}
