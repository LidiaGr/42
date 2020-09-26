/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 15:25:56 by ttarsha           #+#    #+#             */
/*   Updated: 2020/05/23 22:52:03 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_signcounter(long nb)
{
	int		len;

	len = 1;
	while (nb / 10)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

static void		ft_negativ(char *str, long nb, int len)
{
	str[len + 1] = '\0';
	while (len)
	{
		str[len] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
	str[len] = '-';
}

static void		ft_positiv(char *str, long nb, int len)
{
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
}

char			*ft_itoa(int n)
{
	long	nb;
	int		len;
	int		minus;
	char	*str;

	minus = 0;
	nb = (long)n;
	if (nb < 0)
	{
		minus = 1;
		nb = -nb;
	}
	len = ft_signcounter(nb);
	str = malloc(sizeof(char) * (len + minus + 1));
	if (!str)
		return (NULL);
	if (minus)
		ft_negativ(str, nb, len);
	else
		ft_positiv(str, nb, len);
	return (str);
}
