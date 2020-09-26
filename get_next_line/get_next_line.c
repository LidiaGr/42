/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 18:58:40 by ttarsha           #+#    #+#             */
/*   Updated: 2020/07/31 17:06:24 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_check_rest(char **rest, char **line)
{
	char	*n;
	char	*tmp;

	n = NULL;
	if (*rest)
	{
		if ((n = ft_strchr(*rest, '\n')))
		{
			tmp = *rest;
			*n = '\0';
			*line = ft_strdup(*rest);
			*rest = ft_strdup(++n);
			free(tmp);
		}
		else
		{
			*line = ft_strdup(*rest);
			free(*rest);
			*rest = NULL;
		}
	}
	else
		*line = ft_strdup("");
	return (n);
}

int		ft_check_read(ssize_t nbytes, char **line)
{
	if (nbytes < 0)
	{
		free(*line);
		return (-1);
	}
	return (nbytes ? 1 : 0);
}

int		get_line(int fd, char **line, char **rest)
{
	char	*buf;
	ssize_t	bytes;
	char	*n;
	char	*tmp;

	bytes = 1;
	n = ft_check_rest(rest, line);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!n && (((bytes = read(fd, buf, BUFFER_SIZE)) > 0)))
	{
		buf[bytes] = '\0';
		if ((n = ft_strchr(buf, '\n')))
		{
			*n = '\0';
			*rest = ft_strdup(++n);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buf)))
			return (-1);
		free(tmp);
	}
	free(buf);
	return (ft_check_read(bytes, line));
}

t_list	*ft_create_node(int fd)
{
	t_list *list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	list->fd = fd;
	list->rest = NULL;
	list->next = NULL;
	return (list);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*begin_list;
	t_list			*tmp;
	int				res;

	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	if (begin_list == NULL)
		begin_list = ft_create_node(fd);
	if (!begin_list)
		return (-1);
	tmp = begin_list;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			if (!(tmp->next = ft_create_node(fd)))
			{
				ft_free_list(fd, &begin_list);
				return (-1);
			}
		tmp = tmp->next;
	}
	res = get_line(tmp->fd, line, &tmp->rest);
	if (res <= 0)
		ft_free_list(fd, &begin_list);
	return (res);
}
