/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 21:29:40 by ttarsha           #+#    #+#             */
/*   Updated: 2020/05/20 21:14:19 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (j < ft_strlen(set))
	{
		if (s1[i] == set[j])
		{
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_str;
	int		end;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	while (j < ft_strlen(set))
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	if (i == ft_strlen(s1) || ft_strlen(s1) < j)
		return (ft_strdup(s1 + i));
	end = ft_end(s1, set) + 1;
	trimmed_str = ft_substr(s1, i, end - i);
	return (trimmed_str);
}
