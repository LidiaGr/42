/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_with_width_and_flags.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 15:04:19 by ttarsha           #+#    #+#             */
/*   Updated: 2020/07/13 22:31:51 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_check_flag_minus(t_mylist *list, char **data, char **list_str)
{
	char	*print;

	if ((*list).flags.minus == 0)
	{
		if ((*list).type != 's' || (*list).type != 'c')
		{
			if (*data[0] == '-' && (*list).flags.zero == 1)
			{
				*data[0] = '0';
				*list_str[0] = '-';
			}
		}
		print = ft_strjoin(*list_str, *data);
	}
	else
		print = ft_strjoin(*data, *list_str);
	return (print);
}

int		print_with_width_and_flags(t_mylist *list, char *data, int len)
{
	char	*list_str;
	char	*print;

	if (!(list_str = (char*)malloc(sizeof(char) * (((*list).width - len) + 1))))
		exit(0);
	list_str[((*list).width - len)] = '\0';
	if ((*list).flags.zero == 0)
		list_str = ft_memset(list_str, ' ', ((*list).width - len));
	else
		list_str = ft_memset(list_str, '0', ((*list).width - len));
	print = ft_check_flag_minus(list, &data, &list_str);
	len += ((*list).width - len);
	write(1, print, len);
	free(list_str);
	free(print);
	return (len);
}
