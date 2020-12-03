/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:05:40 by ttarsha           #+#    #+#             */
/*   Updated: 2020/11/30 21:28:33 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_action(t_input *input, char *s2, long start_sim, int flag)
{
	char	*str;
	char	*tmp;
	long	sec;
	char	*s1;

	if (g_death)
		return ;
	sec = get_time_in_ms() - start_sim;
	tmp = ft_itoa(sec);
	str = ft_strjoin(tmp, " ");
	free(tmp);
	s1 = ft_itoa(input->philo->name);
	tmp = ft_strjoin(str, s1);
	free(str);
	free(s1);
	str = ft_strjoin(tmp, s2);
	free(tmp);
	sem_wait(input->table.print);
	if (!g_death)
		write(1, str, ft_strlen(str));
	if (flag)
		g_death = 1;
	free(str);
	sem_post(input->table.print);
}

void	take_forks(t_input *tmp, long start_sim)
{
	sem_wait(tmp->table.waiter);
	sem_wait(tmp->table.forks);
	ft_action(tmp, " took first fork\n", start_sim, 0);
	sem_wait(tmp->table.forks);
	ft_action(tmp, " took second fork\n", start_sim, 0);
	sem_post(tmp->table.waiter);
}

void	*check_death(void *args)
{
	t_input	*input;
	long	alive;

	input = (t_input *)args;
	alive = get_time_in_ms();
	while (alive - input->philo->last_meal <= input->time_die)
	{
		sem_wait(input->table.dead);
		alive = get_time_in_ms();
		sem_post(input->table.dead);
	}
	sem_wait(input->table.dead);
	if (input->num_eat == input->philo->eat_count)
		g_death = 1;
	ft_action(input, "\033[31m is dead\033[0m\n", input->philo->start_sim, 1);
	sem_post(input->table.dead);
	return (NULL);
}

void	*ft_simulation(void *args)
{
	t_input		*tmp;
	pthread_t	death;

	tmp = (t_input *)args;
	tmp->philo->start_sim = get_time_in_ms();
	tmp->philo->last_meal = tmp->philo->start_sim;
	pthread_create(&death, NULL, check_death, args);
	while (!g_death)
	{
		take_forks(tmp, tmp->philo->start_sim);
		ft_action(tmp, " is eating\n", tmp->philo->start_sim, 0);
		sem_wait(tmp->table.time);
		tmp->philo->last_meal = get_time_in_ms();
		sem_post(tmp->table.time);
		ft_sleep(tmp->time_eat);
		sem_post(tmp->table.forks);
		sem_post(tmp->table.forks);
		if (++tmp->philo->eat_count && tmp->philo->eat_count == tmp->num_eat)
			break ;
		ft_action(tmp, " is sleeping\n", tmp->philo->start_sim, 0);
		ft_sleep(tmp->time_sleep);
		ft_action(tmp, " is thinking\n", tmp->philo->start_sim, 0);
	}
	pthread_join(death, NULL);
	return (NULL);
}

void	create_threads(t_input *input)
{
	pthread_t				*threads;
	t_input					*args;
	int						i;

	if (!(threads = malloc(sizeof(pthread_t) * input->num_philo)))
		error_exit("Error: Malloc.\n");
	if (!(args = malloc(sizeof(t_input) * input->num_philo)))
		error_exit("Error: Malloc.\n");
	input->threads = threads;
	fill_node(input, args);
	i = -1;
	while (++i < input->num_philo)
		if (pthread_create(&threads[i], NULL, ft_simulation, &args[i]) != 0)
			return ;
	i = -1;
	while (++i < input->num_philo)
		if (pthread_join(threads[i], NULL) != 0)
			return ;
	free(args);
}
