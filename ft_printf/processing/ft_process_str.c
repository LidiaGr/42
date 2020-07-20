/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 14:54:38 by ttarsha           #+#    #+#             */
/*   Updated: 2020/07/13 22:32:11 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_process_str(t_mylist *list, va_list *argp)
{
	char	*str;
	int		len;
	char	*tmp;

	tmp = 0;
	str = va_arg(*argp, char *);
	if (str == NULL)
		str = "(null)";
	len = (int)ft_strlen(str);
	if ((*list).precision < len)
	{
		tmp = ft_substr(str, 0, (*list).precision);
		str = tmp;
		len = (int)ft_strlen(str);
	}
	if ((*list).width > len)
		len = print_with_width_and_flags(list, str, len);
	else
		write(1, str, len);
	free(tmp);
	(*list).length += len;
}
