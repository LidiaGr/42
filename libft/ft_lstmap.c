/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarsha <ttarsha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 21:40:35 by ttarsha           #+#    #+#             */
/*   Updated: 2020/05/20 20:59:12 by ttarsha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin;
	t_list	*current;
	t_list	*lstcpy;

	if (!lst || !f)
		return (NULL);
	begin = ft_lstnew(f(lst->content));
	if (!begin)
		return (NULL);
	current = begin;
	lstcpy = lst->next;
	while (lstcpy)
	{
		current->next = ft_lstnew(f(lstcpy->content));
		current = current->next;
		if (!current)
		{
			ft_lstclear(&begin, del);
			return (NULL);
		}
		lstcpy = lstcpy->next;
	}
	return (begin);
}
