/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:32:20 by ttarsha           #+#    #+#             */
/*   Updated: 2020/11/28 18:47:51 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long	get_time_in_ms(void)
{
	struct timeval	time;
	long			moment;

	if (gettimeofday(&time, NULL) != 0)
		return (0);
	moment = time.tv_sec * 1000 + time.tv_usec * 0.001;
	return (moment);
}

void	ft_sleep(int value)
{
	int		begin;
	int		end;
	int		diff;

	begin = get_time_in_ms();
	end = get_time_in_ms();
	diff = end - begin;
	while (diff < value)
	{
		end = get_time_in_ms();
		diff = end - begin;
		usleep(10);
	}
}

void	fill_node(t_input *input, t_input *args)
{
	int			i;

	i = -1;
	while (++i < input->num_philo)
	{
		args[i].philo = &input->philo[i];
		args[i].table = input->table;
		args[i].time_eat = input->time_eat;
		args[i].time_sleep = input->time_sleep;
		args[i].time_die = input->time_die;
		args[i].num_eat = input->num_eat;
		args[i].threads = &input->threads[i];
		args[i].num_philo = input->num_philo;
		args[i].philo->eat_count = 0;
	}
}

void	clear_input(t_input *input)
{
	int		i;

	i = 0;
	free(input->philo);
	free(input->table.forks);
	free(input->threads);
	while (i < input->num_philo)
		pthread_mutex_destroy(&input->table.forks[i++]);
	pthread_mutex_destroy(&g_dead);
	pthread_mutex_destroy(&g_print);
}
