/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 18:49:57 by ttarsha           #+#    #+#             */
/*   Updated: 2020/11/28 18:54:42 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int		main(int ac, char **av)
{
	t_input input;

	g_death = 0;
	pthread_mutex_init(&g_dead, NULL);
	pthread_mutex_init(&g_print, NULL);
	if (validate_args(ac, av))
		return (1);
	input = init_args(av);
	if (init_philo(&input))
		return (1);
	if (init_table(&input))
		return (1);
	if (create_threads(&input))
		return (1);
	clear_input(&input);
	return (0);
}
