/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 14:42:34 by ttarsha           #+#    #+#             */
/*   Updated: 2020/07/13 22:32:01 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_process_decimals(t_mylist *list, va_list *argp)
{
	int		num;
	char	*num_str;
	int		len;

	len = 0;
	num = va_arg(*argp, int);
	num_str = ft_itoa(num);
	if ((num == 0) && ((*list).precision == 0))
	{
		free(num_str);
		num_str = ft_strdup("");
	}
	len = (int)ft_strlen(num_str);
	if ((*list).precision >= len)
		num_str = fill_precision(list, num_str, len);
	len = (int)ft_strlen(num_str);
	if ((*list).width > len)
		len = print_with_width_and_flags(list, num_str, len);
	else
		write(1, num_str, len);
	free(num_str);
	(*list).length += len;
}
