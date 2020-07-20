/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 14:52:14 by ttarsha           #+#    #+#             */
/*   Updated: 2020/07/13 22:31:57 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_process_char(t_mylist *list, va_list *argp)
{
	char	sym;
	char	*sym_str;
	int		len;

	len = 1;
	sym = va_arg(*argp, unsigned int);
	if ((*list).width > len)
	{
		if (sym == '\0' && (*list).flags.minus == 1)
		{
			write(1, &sym, 1);
			len = 0;
			(*list).width--;
			(*list).length++;
		}
		if (!(sym_str = (char *)malloc(sizeof(char) * 2)))
			exit(0);
		sym_str[0] = sym;
		sym_str[1] = '\0';
		len = print_with_width_and_flags(list, sym_str, len);
		free(sym_str);
	}
	else
		write(1, &sym, 1);
	(*list).length += len;
}
