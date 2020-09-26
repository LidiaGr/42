/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:29:50 by ttarsha           #+#    #+#             */
/*   Updated: 2020/09/14 18:48:13 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		main(int ac, char **av)
{
	t_all	all;
	int		fd;

	if (ac == 3 && (ft_name_check(av[1], ".cub")) \
		&& (!(ft_strncmp(av[2], "--save", ft_strlen(av[2]) + 1))))
		all.tools.save = 1;
	else if (ac == 2 && (ft_name_check(av[1], ".cub")))
		all.tools.save = 0;
	else
		exit_game(EINVAL, "Input");
	if ((fd = open(av[1], O_RDONLY)) < 0)
		exit_game(EINVAL, "Fd map");
	init_pre(&all);
	ft_parser(&all, &fd);
	init_picture(&all);
	if (all.tools.save != 1)
	{
		mlx_hook(all.win.ptr, 2, 1L << 0, set_walls, &all);
		mlx_hook(all.win.ptr, 17, 1L << 17, close_win, &all);
		mlx_loop(all.mlx.ptr);
	}
	return (0);
}
