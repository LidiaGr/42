/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:07:18 by ttarsha           #+#    #+#             */
/*   Updated: 2020/11/27 20:27:13 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int		validate_args(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 5 || ac > 6)
		return (error_exit("Error: Bad arguments.\n"));
	while (av[++i])
	{
		if (ft_str_is_digit(av[i]) == 0 || ft_atoi(av[i]) <= 0)
			return (error_exit("Error: Bad arguments.\n"));
	}
	return (0);
}

t_input	init_args(char **av)
{
	t_input	input;

	input.num_philo = ft_atoi(av[1]);
	input.time_die = ft_atoi(av[2]);
	input.time_eat = ft_atoi(av[3]);
	input.time_sleep = ft_atoi(av[4]);
	if (av[5])
		input.num_eat = ft_atoi(av[5]);
	else
		input.num_eat = -1;
	return (input);
}

int		init_philo(t_input *input)
{
	t_philo	*new;
	int		i;

	i = -1;
	if (!(new = malloc(sizeof(t_philo) * input->num_philo)))
		return (error_exit("Error: Malloc.\n"));
	input->philo = new;
	while (++i < input->num_philo)
	{
		input->philo[i].name = i + 1;
		input->philo[i].right_fork = i;
		if ((i + 1) != input->num_philo)
			input->philo[i].left_fork = i + 1;
		else
			input->philo[i].left_fork = 0;
	}
	return (0);
}

int		init_table(t_input *input)
{
	int				i;
	t_table			table;
	pthread_mutex_t *forks;

	i = -1;
	if (!(forks = malloc(sizeof(pthread_mutex_t) * input->num_philo)))
		return (error_exit("Error: Malloc.\n"));
	table.forks = forks;
	input->table = table;
	while (++i < input->num_philo)
		pthread_mutex_init(&input->table.forks[i], NULL);
	return (0);
}
