/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmillier <nmillier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:52:53 by nmillier          #+#    #+#             */
/*   Updated: 2023/11/11 15:12:47 by nmillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*newstring;
	long unsigned	i;

	if (!s)
		return (NULL);
	i = 0;
	if (start >= (unsigned int) ft_strlen(s))
		len = 0;
	else if (start + len > (unsigned int) ft_strlen(s))
		len = ft_strlen(s) - start;
	newstring = (char *) malloc((len + 1) * sizeof(char));
	if (newstring == NULL)
		return (NULL);
	while (i < len)
	{
		newstring[i] = s[start + i];
		i++;
	}
	newstring[i] = '\0';
	return (newstring);
}
