/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstwritecontent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmillier <nmillier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 23:00:17 by ydred             #+#    #+#             */
/*   Updated: 2023/11/12 18:31:16 by nmillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_lstwritecontentlen(t_list **lst)
{
	t_list	*current;
	int		fulllen;

	current = *lst;
	fulllen = 0;
	while (current)
	{
		if (current->content == (void *) 0x1)
			fulllen++;
		else
			fulllen += ft_strlen((char *) current->content);
		current = current->next;
	}
	return (fulllen);
}

void	ft_lstwritecontentcpy(t_list **lst, char *ptr)
{
	t_list	*cur;

	cur = *lst;
	while (cur)
	{
		if (cur->content == (void *) 0x1)
		{
			cur->content = NULL;
			*(ptr++) = '\0';
		}
		else
			ptr += ft_strlcpy(ptr, cur->content, ft_strlen(cur->content) + 1);
		cur = cur->next;
	}
}

int	ft_lstwritecontent(t_list **lst, int fd)
{
	char	*fullstr;
	char	*ptr;
	int		fulllen;

	fulllen = 0;
	fulllen = ft_lstwritecontentlen(lst);
	fullstr = (char *) ft_calloc(fulllen + 1, sizeof(char));
	if (!fullstr)
		return (0);
	ptr = fullstr;
	ft_memset(fullstr, 0, fulllen + 1);
	ft_lstwritecontentcpy(lst, ptr);
	write(fd, fullstr, fulllen);
	free(fullstr);
	return (fulllen);
}
