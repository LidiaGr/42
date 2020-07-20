/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:31:00 by ttarsha           #+#    #+#             */
/*   Updated: 2020/05/23 22:49:37 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
