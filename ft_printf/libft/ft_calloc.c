/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 18:34:23 by ttarsha           #+#    #+#             */
/*   Updated: 2020/07/13 22:33:21 by ttarsha          ###   ########.fr       */
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
