/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 14:50:23 by ttarsha           #+#    #+#             */
/*   Updated: 2020/07/13 22:32:07 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_process_pointer(t_mylist *list, va_list *argp)
{
	void	*num;
	char	*num_str;
	char	*tmp;
	int		len;

	len = 0;
	tmp = 0;
	num = va_arg(*argp, void *);
	if (num == NULL && (*list).precision == -1)
		num_str = ft_strdup("0x0");
	else if (num == NULL && (*list).precision >= 0)
		num_str = ft_strdup("0x");
	else
	{
		tmp = ft_itoa_base16_bonus((unsigned long int)num);
		num_str = ft_strjoin("0x", tmp);
	}
	len = (int)ft_strlen(num_str);
	if ((*list).width > len)
		len = print_with_width_and_flags(list, num_str, len);
	else
		write(1, num_str, len);
	free(tmp);
	free(num_str);
	(*list).length += len;
}
