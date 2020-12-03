/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:05:40 by ttarsha           #+#    #+#             */
/*   Updated: 2020/11/30 20:42:20 by ttarsha          ###   ########.fr       */
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
	pthread_mutex_lock(&g_print);
	if (!g_death)
		write(1, str, ft_strlen(str));
	if (flag)
		g_death = 1;
	free(str);
	pthread_mutex_unlock(&g_print);
}

void	take_forks(t_input *tmp, long start_sim)
{
	if (tmp->philo->name % 2 == 0)
	{
		pthread_mutex_lock(&tmp->table.forks[tmp->philo->left_fork]);
		ft_action(tmp, " took left fork\n", start_sim, 0);
		pthread_mutex_lock(&tmp->table.forks[tmp->philo->right_fork]);
		ft_action(tmp, " took right fork\n", start_sim, 0);
	}
	else
	{
		pthread_mutex_lock(&tmp->table.forks[tmp->philo->right_fork]);
		ft_action(tmp, " took right fork\n", start_sim, 0);
		pthread_mutex_lock(&tmp->table.forks[tmp->philo->left_fork]);
		ft_action(tmp, " took left fork\n", start_sim, 0);
	}
}

void	*check_death(void *args)
{
	t_input					*input;
	long					alive;

	input = (t_input *)args;
	alive = get_time_in_ms();
	while (alive - input->philo->last_meal <= input->time_die)
	{
		pthread_mutex_lock(&g_dead);
		alive = get_time_in_ms();
		pthread_mutex_unlock(&g_dead);
	}
	if (input->num_eat == input->philo->eat_count)
		g_death = 1;
	ft_action(input, "\033[31m is dead\033[0m\n", input->philo->start_sim, 1);
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
		pthread_mutex_lock(&tmp->table.time);
		tmp->philo->last_meal = get_time_in_ms();
		pthread_mutex_unlock(&tmp->table.time);
		ft_sleep(tmp->time_eat);
		pthread_mutex_unlock(&tmp->table.forks[tmp->philo->right_fork]);
		pthread_mutex_unlock(&tmp->table.forks[tmp->philo->left_fork]);
		if (tmp->philo->eat_count++ && tmp->philo->eat_count == tmp->num_eat)
			break ;
		ft_action(tmp, " is sleeping\n", tmp->philo->start_sim, 0);
		ft_sleep(tmp->time_sleep);
		ft_action(tmp, " is thinking\n", tmp->philo->start_sim, 0);
	}
	pthread_join(death, NULL);
	return (NULL);
}

int		create_threads(t_input *input)
{
	pthread_t				*threads;
	t_input					*args;
	int						i;
	static pthread_mutex_t	time = PTHREAD_MUTEX_INITIALIZER;

	if (!(threads = malloc(sizeof(pthread_t) * input->num_philo)))
		return (error_exit("Error: Malloc.\n"));
	if (!(args = malloc(sizeof(t_input) * input->num_philo)))
		return (error_exit("Error: Malloc.\n"));
	input->threads = threads;
	input->table.time = time;
	fill_node(input, args);
	i = -1;
	while (++i < input->num_philo)
		if (pthread_create(&threads[i], NULL, ft_simulation, &args[i]) != 0)
			return (error_exit("Error: Pthread create.\n"));
	i = -1;
	while (++i < input->num_philo)
		if (pthread_join(threads[i], NULL) != 0)
			return (error_exit("Error: Pthread join.\n"));
	pthread_mutex_destroy(&time);
	free(args);
	return (0);
}
