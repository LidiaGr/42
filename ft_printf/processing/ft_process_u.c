/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 14:56:00 by ttarsha           #+#    #+#             */
/*   Updated: 2020/07/13 22:32:14 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_process_unsigned_int(t_mylist *list, va_list *argp)
{
	unsigned int	num;
	char			*num_str;
	int				len;

	len = 0;
	num = va_arg(*argp, unsigned int);
	if (num == 0 && ((*list).precision == 0))
		num_str = ft_strdup("");
	else
		num_str = ft_itoa(num);
	len = (int)ft_strlen(num_str);
	if ((*list).precision > len)
		num_str = fill_precision(list, num_str, len);
	len = (int)ft_strlen(num_str);
	if ((*list).width > len)
		len = print_with_width_and_flags(list, num_str, len);
	else
		write(1, num_str, len);
	free(num_str);
	(*list).length += len;
}
