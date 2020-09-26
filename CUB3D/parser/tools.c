/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:29:50 by ttarsha           #+#    #+#             */
/*   Updated: 2020/09/15 14:48:56 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		ft_name_check(char *s1, char *s2)
{
	if (*s1 == '.')
		exit_game(EINVAL, ".cub");
	while (*s1 != '.' && *s1)
		s1++;
	if (*s1 == '\0')
		exit_game(EINVAL, "Wrong file extension");
	if (*s1 == '.')
	{
		if ((ft_strncmp(s1, s2, ft_strlen(s1) + 1) != 0))
			exit_game(EINVAL, "Wrong file extension");
		else
			return (1);
	}
	return (0);
}

int		num_len_base(int num, int base)
{
	int len;

	len = 1;
	while (num >= base)
	{
		num /= base;
		len++;
	}
	return (len);
}

int		ft_check_tail(char *s)
{
	while (*s != '\0')
	{
		if (*s != ' ')
			return (1);
		else
			s++;
	}
	return (0);
}

void	free_arr(char **arr, int lines)
{
	int	i;

	i = 0;
	while (i < lines)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
