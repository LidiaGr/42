/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:19:02 by ttarsha           #+#    #+#             */
/*   Updated: 2020/11/30 20:44:14 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

pthread_mutex_t		g_dead;
pthread_mutex_t		g_print;
int					g_death;

typedef struct		s_table
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	time;
}					t_table;

typedef struct		s_philo
{
	int				name;
	unsigned int	left_fork;
	unsigned int	right_fork;
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
}					t_input;

/*
**utils
*/
int					ft_strlen(char *s);
int					ft_atoi(const char *str);
int					ft_str_is_digit(char *str);
char				*ft_itoa(long n);
int					error_exit(char *str);
char				*ft_strjoin(char *s1, char *s2);
void				clear_input(t_input *input);
/*
**init
*/
int					validate_args(int ac, char **av);
t_input				init_args(char **av);
int					init_philo(t_input *input);
int					init_table(t_input *input);
/*
**simulation
*/
long				get_time_in_ms(void);
void				ft_action(t_input *input, char *s2, long start_sim, \
																int flag);
void				ft_sleep(int value);
void				fill_node(t_input *input, t_input *args);
int					create_threads(t_input *input);

#endif
