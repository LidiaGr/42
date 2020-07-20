/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 18:59:44 by ttarsha           #+#    #+#             */
/*   Updated: 2020/06/23 22:50:58 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!cpy)
		return (NULL);
	while (src[i] != '\0')
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != c)
	{
		if (!(*s))
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	len;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	newstr = malloc(sizeof(char) * len);
	if (!newstr)
		return (NULL);
	while (*s1 != '\0')
		newstr[i++] = *s1++;
	while (*s2 != '\0')
		newstr[i++] = *s2++;
	newstr[i] = '\0';
	return (newstr);
}

void	ft_free_list(int fd, t_list **begin_list)
{
	t_list	*tmp;
	t_list	*head;

	if ((*begin_list)->fd == fd)
	{
		tmp = (*begin_list)->next;
		free(((*begin_list)->rest));
		free(*begin_list);
		*begin_list = tmp;
	}
	else
	{
		head = *begin_list;
		while ((*begin_list)->fd != fd)
		{
			tmp = *begin_list;
			*begin_list = (*begin_list)->next;
		}
		tmp->next = (*begin_list)->next;
		free(((*begin_list)->rest));
		free(*begin_list);
		*begin_list = head;
	}
}
