/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:29:50 by ttarsha           #+#    #+#             */
/*   Updated: 2020/09/15 14:48:25 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*add_sym(char *s, char *c)
{
	char	*cpy;
	int		i;

	i = 0;
	if (!(cpy = (char *)malloc(sizeof(char) * ft_strlen(s) + 2)))
		return (NULL);
	while (s && s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i++] = c[0];
	cpy[i] = '\0';
	return (cpy);
}

int		get_next_line(char **line, int fd)
{
	char		buf[1];
	ssize_t		bytes;
	static char	*str;
	char		*tmp;

	while ((bytes = read(fd, buf, 1)) > 0)
	{
		if (buf[0] != '\n')
		{
			tmp = str;
			str = add_sym(str, buf);
			free(tmp);
		}
		else
			break ;
	}
	*line = ft_strdup(str);
	free(str);
	str = NULL;
	if (bytes < 0)
		return (-1);
	return (bytes ? 1 : 0);
}
