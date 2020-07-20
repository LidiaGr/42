/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 19:00:11 by ttarsha           #+#    #+#             */
/*   Updated: 2020/06/23 22:13:12 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	int				fd;
	char			*rest;
	struct s_list	*next;
}					t_list;

int					get_next_line(int fd, char **line);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *src);
char				*ft_strchr(const char *s, int c);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_free_list(int fd, t_list **list);

#endif
