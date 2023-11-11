/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmillier <nmillier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 04:18:30 by ydred             #+#    #+#             */
/*   Updated: 2023/11/11 15:12:47 by nmillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static t_list	*ft_failedmalloc(t_list *lst, void (*del)(void *), void *c)
{
	del(c);
	ft_lstclear(&lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*current;
	t_list	*currentnew;
	void	*content;

	if (lst == NULL)
		return (NULL);
	current = lst;
	content = f(current->content);
	newlst = ft_lstnew(content);
	if (newlst == NULL || newlst->content == NULL)
		return (ft_failedmalloc(newlst, del, content));
	currentnew = newlst;
	while (current->next)
	{
		content = f(current->next->content);
		currentnew->next = ft_lstnew(content);
		if (currentnew->next == NULL || currentnew->next->content == NULL)
			return (ft_failedmalloc(newlst, del, content));
		currentnew = currentnew->next;
		current = current->next;
	}
	return (newlst);
}
