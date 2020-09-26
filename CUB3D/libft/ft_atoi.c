/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:31:00 by ttarsha           #+#    #+#             */
/*   Updated: 2020/09/14 14:59:54 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_check_maxmin(long *buff)
{
	if (*buff > 2147483647)
		*buff = 2147483647;
	if (*buff < -2147483648)
		*buff = -2147483647;
}

int		ft_atoi(const char *str)
{
	long	buff;
	int		minus;

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
	ft_check_maxmin(&buff);
	return (buff);
}
