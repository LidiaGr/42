/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 14:44:23 by ttarsha           #+#    #+#             */
/*   Updated: 2020/07/13 22:32:19 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_process_heximals(t_mylist *list, va_list *argp)
{
	unsigned int	num;
	char			*num_str;
	int				len;
	int				i;

	i = 0;
	num = va_arg(*argp, unsigned int);
	if (num == 0 && ((*list).precision == 0))
		num_str = ft_strdup("");
	else
		num_str = ft_itoa_base16_bonus(num);
	if ((*list).type == 'X')
	{
		while ((num_str[i] = ft_toupper(num_str[i])))
			i++;
	}
	if ((*list).precision > (len = (int)ft_strlen(num_str)))
		num_str = fill_precision(list, num_str, len);
	len = (int)ft_strlen(num_str);
	if ((*list).width > len)
		len = print_with_width_and_flags(list, num_str, len);
	else
		write(1, num_str, len);
	free(num_str);
	(*list).length += len;
}
