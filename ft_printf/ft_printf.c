/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 11:41:23 by ttarsha           #+#    #+#             */
/*   Updated: 2020/07/13 22:41:05 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	make_flist(t_flaglist *flist)
{
	(*flist).minus = 0;
	(*flist).zero = 0;
}

void	make_list(t_mylist *list)
{
	t_flaglist flist;

	make_flist(&flist);
	(*list).flags = flist;
	(*list).width = 0;
	(*list).precision = -1;
	(*list).type = 0;
	(*list).length = 0;
}

void	list_reset(t_mylist *list)
{
	t_flaglist flist;

	make_flist(&flist);
	(*list).flags = flist;
	(*list).width = 0;
	(*list).precision = -1;
	(*list).type = 0;
}

int		check_symbols_for_write(const char *src, va_list *argp, t_mylist *list)
{
	while (*src != '%' && *src != '\0')
	{
		write(1, src, 1);
		src++;
		(*list).length++;
	}
	if (*src == '%')
	{
		src++;
		list_reset(list);
		ft_parsing(src, list, argp);
	}
	return ((*list).length);
}

int		ft_printf(const char *src, ...)
{
	va_list		argp;
	t_mylist	list;
	int			len;

	make_list(&list);
	va_start(argp, src);
	len = check_symbols_for_write(src, &argp, &list);
	va_end(argp);
	return (len);
}
