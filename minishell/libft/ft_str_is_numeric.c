/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 11:57:11 by pfile             #+#    #+#             */
/*   Updated: 2020/05/21 12:04:08 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int i;

	i = -1;
	if (str[0] == '\0')
		return (1);
	while (str[++i] != '\0')
		if (str[i] < 48 || str[i] > 57)
			return (0);
	return (1);
}
