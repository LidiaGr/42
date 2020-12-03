/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:19:02 by ttarsha           #+#    #+#             */
/*   Updated: 2020/12/01 13:53:52 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

int			g_death;
sem_t		*g_dead;
sem_t		*g_print;

typedef struct		s_table
{
	sem_t	*forks;
	sem_t	*time;
	sem_t	*print;
	sem_t	*dead;
	sem_t	*waiter;
}					t_table;

typedef struct		s_philo
{
	int				name;
	long			last_meal;
	long			start_sim;
	int				eat_count;
}					t_philo;

typedef struct		s_input
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_eat;
	struct s_philo	*philo;
	t_table			table;
	pthread_t		*threads;
	pid_t			*pid;
}					t_input;

/*
**utils
*/
int					ft_strlen(char *s);
int					ft_atoi(const char *str);
int					ft_str_is_digit(char *str);
char				*ft_itoa(long n);
void				error_exit(char *str);
char				*ft_strjoin(char *s1, char *s2);
void				clear_input(t_input *input);
/*
**init
*/
int					validate_args(int ac, char **av);
t_input				init_args(char **av);
void				init_philo(t_input *input);
void				init_table(t_input *input);
/*
**threads
*/
long				get_time_in_ms(void);
void				ft_action(t_input *input, char *s2, long start_sim, \
																int flag);
void				ft_sleep(int value);
void				fill_node(t_input *input, t_input *args);
void				create_threads(t_input *input);

#endif
