/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstwritecontent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydred <ydred@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 23:00:17 by ydred             #+#    #+#             */
/*   Updated: 2023/11/11 23:36:42 by ydred            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_lstwritecontent(t_list **lst, int fd)
{
	t_list	*current;
	char	*fullstr;
	int		fulllen;
	(void) fd;
	(void) lst;

	current = *lst;
	fulllen = 0;
	while (current)
	{
		fulllen += ft_strlen((char *) current->content);
		current = current->next;
	}
	fullstr = (char *) malloc((fulllen + 1) * sizeof(char));
	ft_memset(fullstr, 0, fulllen + 1);
	current = *lst;
	while (current)
	{
		ft_strlcat(fullstr, (char *) current->content, fulllen + 1);
		current = current->next;
	}
	write(fd, fullstr, fulllen + 1);
	free(fullstr);
}
