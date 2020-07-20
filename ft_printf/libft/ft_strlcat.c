/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 12:45:04 by ttarsha           #+#    #+#             */
/*   Updated: 2020/07/13 22:36:06 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	i;

	d_len = 0;
	i = 0;
	while (dst[d_len] && (d_len < size))
		d_len++;
	i = d_len;
	while (src[d_len - i] && ((d_len + 1) < size))
	{
		dst[d_len] = src[d_len - i];
		d_len++;
	}
	if (i < size)
		dst[d_len] = '\0';
	return (i + ft_strlen(src));
}
