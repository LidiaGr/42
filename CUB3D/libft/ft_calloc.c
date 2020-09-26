/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 18:34:23 by ttarsha           #+#    #+#             */
/*   Updated: 2020/05/19 22:22:21 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	plus;

	plus = nmemb * size;
	if (nmemb == 0 || size == 0)
		plus = 1;
	mem = malloc(plus);
	if (!mem)
		return (NULL);
	ft_memset(mem, 0, plus);
	return (mem);
}
