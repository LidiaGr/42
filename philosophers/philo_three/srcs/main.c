/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 18:49:57 by ttarsha           #+#    #+#             */
/*   Updated: 2020/12/03 12:21:02 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int		main(int ac, char **av)
{
	t_input input;

	g_death = 0;
	if (validate_args(ac, av))
		return (1);
	input = init_args(av);
	init_philo(&input);
	init_table(&input);
	create_threads(&input);
	clear_input(&input);
	return (0);
}
