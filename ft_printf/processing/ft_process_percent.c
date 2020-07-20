/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 14:49:13 by ttarsha           #+#    #+#             */
/*   Updated: 2020/07/13 22:32:04 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_process_percent(t_mylist *list)
{
	char	sym;
	char	*sym_str;
	int		len;

	len = 1;
	sym = '%';
	if ((*list).width > len)
	{
		sym_str = ft_strdup(&sym);
		len = print_with_width_and_flags(list, sym_str, len);
		free(sym_str);
	}
	else
		write(1, &sym, 1);
	(*list).length += len;
}
