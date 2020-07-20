/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 15:06:43 by ttarsha           #+#    #+#             */
/*   Updated: 2020/05/23 22:30:49 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordcount(const char *s, char c)
{
	size_t	words;
	int		flag;

	words = 0;
	flag = 0;
	while (*s)
	{
		if (*s == c && flag == 1)
			flag = 0;
		if (*s != c && flag == 0)
		{
			flag = 1;
			words++;
		}
		s++;
	}
	return (words);
}

static char		*ft_createstr(const char *s, char c)
{
	int		len;
	char	*str;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, len + 1);
	return (str);
}

static void		ft_freearr(char **arr, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	exit(0);
}

char			**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	words;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	words = ft_wordcount(s, c);
	arr = malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	while (i < words)
	{
		while (*s == c)
			s++;
		arr[i] = ft_createstr(s, c);
		if (!arr[i])
			ft_freearr(arr, words);
		s = s + ft_strlen(arr[i]);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
