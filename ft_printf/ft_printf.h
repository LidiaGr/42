/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 11:53:11 by ttarsha           #+#    #+#             */
/*   Updated: 2020/07/13 22:30:27 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_flist
{
	int		minus;
	int		zero;
}				t_flaglist;

typedef struct	s_slist
{
	t_flaglist	flags;
	int			width;
	int			precision;
	char		type;
	int			length;
}				t_mylist;

int				ft_printf(const char *src, ...);
int				check_symbols_for_write(const char *src, va_list *argp,
				t_mylist *list);
void			ft_parsing(const char *src, t_mylist *list, va_list *argp);
void			ft_process_str(t_mylist *list, va_list *argp);
void			ft_process_char(t_mylist *list, va_list *argp);
void			ft_process_percent(t_mylist *list);
void			ft_process_unsigned_int(t_mylist *list, va_list *argp);
void			ft_process_decimals(t_mylist *list, va_list *argp);
void			ft_process_pointer(t_mylist *list, va_list *argp);
void			ft_process_heximals(t_mylist *list, va_list *argp);
int				print_with_width_and_flags(t_mylist *list, char *data, int len);
char			*fill_precision(t_mylist *list, char *data, int len);

#endif
