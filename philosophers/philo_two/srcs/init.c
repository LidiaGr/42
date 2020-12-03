/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:07:18 by ttarsha           #+#    #+#             */
/*   Updated: 2020/11/30 16:24:05 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int		validate_args(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 5 || ac > 6)
	{
		error_exit("Error: Bad arguments.\n");
		return (1);
	}
	while (av[++i])
	{
		if (ft_str_is_digit(av[i]) == 0 || ft_atoi(av[i]) <= 0)
		{
			error_exit("Error: Bad arguments.\n");
			return (1);
		}
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

void	init_philo(t_input *input)
{
	t_philo	*new;
	t_table	table;
	int		i;

	i = -1;
	if (!(new = malloc(sizeof(t_philo) * input->num_philo)))
		error_exit("Error: Malloc.\n");
	input->philo = new;
	while (++i < input->num_philo)
		input->philo[i].name = i + 1;
	table.forks = NULL;
	input->table = table;
}

void	init_table(t_input *input)
{
	sem_t	*forks;
	sem_t	*time;
	sem_t	*print;
	sem_t	*dead;
	sem_t	*waiter;

	sem_unlink("forks");
	sem_unlink("time");
	sem_unlink("print");
	sem_unlink("dead");
	sem_unlink("waiter");
	forks = sem_open("forks", O_CREAT, S_IRWXU, input->num_philo);
	time = sem_open("time", O_CREAT, S_IRWXU, 1);
	print = sem_open("print", O_CREAT, S_IRWXU, 1);
	dead = sem_open("dead", O_CREAT, S_IRWXU, 1);
	waiter = sem_open("waiter", O_CREAT, S_IRWXU, 1);
	input->table.forks = forks;
	input->table.time = time;
	input->table.print = print;
	input->table.dead = dead;
	input->table.waiter = waiter;
}
