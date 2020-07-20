/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 15:03:04 by ttarsha           #+#    #+#             */
/*   Updated: 2020/07/13 22:31:49 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*fill_precision(t_mylist *list, char *data, int len)
{
	char	*pre_str;
	int		pre_len;

	if (*data == '-')
		(*list).precision++;
	if (!(pre_str = (char *)malloc(sizeof(char) * (((*list).precision) + 1))))
		exit(0);
	pre_str[(*list).precision] = '\0';
	pre_str = ft_memset(pre_str, '0', (*list).precision);
	pre_len = (*list).precision;
	if (data[0] == '-')
	{
		pre_str[0] = '-';
		data[0] = '0';
	}
	while (--len >= 0)
		pre_str[--pre_len] = data[len];
	free(data);
	return (pre_str);
}
