/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base16_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 15:31:58 by ttarsha           #+#    #+#             */
/*   Updated: 2020/07/13 22:34:04 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	check_count(unsigned long int num)
{
	int		counter;

	counter = 0;
	while (num >= 16)
	{
		num /= 16;
		counter++;
	}
	counter++;
	return (counter);
}

char		*ft_itoa_base16_bonus(unsigned long int data)
{
	char					*str;
	int						one_sym;
	int						counter;
	unsigned long int		num;

	str = 0;
	counter = check_count(data);
	num = data;
	if (!(str = (char*)malloc(sizeof(char) * (counter + 1))))
		return (NULL);
	if (num == 0)
		*str = '0';
	str[counter] = '\0';
	while (num > 0)
	{
		one_sym = num % 16 + '0';
		if (one_sym > '9')
			one_sym += 39;
		str[--counter] = one_sym;
		num /= 16;
	}
	return (str);
}
