/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 14:38:17 by ttarsha           #+#    #+#             */
/*   Updated: 2020/07/13 22:29:49 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*check_flags(const char *src, t_mylist *list)
{
	while (*src == '-' || *src == '0')
	{
		if (*src == '-')
		{
			(*list).flags.minus = 1;
			src++;
		}
		else if (*src == '0')
		{
			(*list).flags.zero = 1;
			src++;
		}
	}
	if ((*list).flags.minus && (*list).flags.zero)
		(*list).flags.zero = 0;
	return (src);
}

const char	*check_width(const char *src, t_mylist *list, va_list *argp)
{
	int	num;

	num = 0;
	if (*src == '*')
	{
		num = va_arg(*argp, int);
		src++;
	}
	else
	{
		num = ft_atoi(src);
		while (ft_isdigit(*src) == 1)
			src++;
	}
	if (num < 0)
	{
		(*list).flags.minus = 1;
		check_flags(src, list);
		num *= -1;
	}
	(*list).width = num;
	return (src);
}

const char	*check_precision(const char *src, t_mylist *list, va_list *argp)
{
	int	num;

	num = -1;
	if (*src == '.')
	{
		src++;
		if (*src == '*')
		{
			num = va_arg(*argp, int);
			src++;
		}
		else if ((ft_isdigit(*src)) == 1)
		{
			num = ft_atoi(src);
			while (ft_isdigit(*src) == 1)
				src++;
		}
		else
			num = 0;
	}
	(*list).precision = num;
	if ((*list).precision >= 0 && (*list).flags.zero == 1 && (*list).width >= 0)
		(*list).flags.zero = 0;
	return (src);
}

const char	*check_type(const char *src, t_mylist *list, va_list *argp)
{
	if (*src == 'd' || *src == 'i' || *src == 'u' || *src == 'c' || *src == 's'
		|| *src == 'p' || *src == 'x' || *src == 'X' || *src == '%')
		(*list).type = *src;
	if (*src == 'd' || *src == 'i')
		ft_process_decimals(list, argp);
	if (*src == 'u')
		ft_process_unsigned_int(list, argp);
	if (*src == 'c')
		ft_process_char(list, argp);
	if (*src == 's')
		ft_process_str(list, argp);
	if (*src == 'p')
		ft_process_pointer(list, argp);
	if (*src == 'x' || *src == 'X')
		ft_process_heximals(list, argp);
	if (*src == '%')
		ft_process_percent(list);
	if (*src == '\0')
		return (src);
	return (++src);
}

void		ft_parsing(const char *src, t_mylist *list, va_list *argp)
{
	src = check_flags(src, list);
	src = check_width(src, list, argp);
	src = check_precision(src, list, argp);
	src = check_type(src, list, argp);
	check_symbols_for_write(src, argp, list);
}
