/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:10:05 by ttarsha           #+#    #+#             */
/*   Updated: 2020/11/27 20:19:04 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int		ft_atoi(const char *str)
{
	int buff;
	int minus;

	buff = 0;
	minus = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
		*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -minus;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		buff = (*str - '0') + (buff * 10);
		str++;
	}
	buff = buff * minus;
	return (buff);
}

int		ft_str_is_digit(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	return (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	size_t	len;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(newstr = malloc(sizeof(char) * len)))
		return (NULL);
	while (*s1 != '\0')
		newstr[i++] = *s1++;
	while (*s2 != '\0')
		newstr[i++] = *s2++;
	newstr[i] = '\0';
	return (newstr);
}

void	error_exit(char *str)
{
	write(1, str, ft_strlen(str));
}
