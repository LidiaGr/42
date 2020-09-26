/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 17:58:03 by ttarsha           #+#    #+#             */
/*   Updated: 2020/05/24 10:55:28 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_rec(long n, int fd)
{
	long i;

	if (n > 9)
		ft_putnbr_rec((n / 10), fd);
	i = n % 10 + '0';
	write(fd, &i, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long i;

	i = 1;
	if (n < 0)
	{
		write(fd, "-", 1);
		i = -1;
	}
	i = i * n;
	ft_putnbr_rec(i, fd);
}
