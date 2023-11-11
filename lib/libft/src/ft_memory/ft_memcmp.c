/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmillier <nmillier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:47:01 by nmillier          #+#    #+#             */
/*   Updated: 2023/11/11 15:12:47 by nmillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*c1;
	const char	*c2;
	int			i;

	c1 = s1;
	c2 = s2;
	i = 0;
	while (n-- > 0)
	{
		if (c1[i] != c2[i])
			return ((unsigned char) c1[i] - (unsigned char) c2[i]);
		i++;
	}
	return (0);
}
