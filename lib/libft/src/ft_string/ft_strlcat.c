/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmillier <nmillier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:40:47 by nmillier          #+#    #+#             */
/*   Updated: 2023/11/11 15:12:47 by nmillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*src_ptr;
	char	*dst_ptr;
	size_t	dst_len;

	src_ptr = (char *) src;
	dst_ptr = dst;
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (ft_strlen(src) + size);
	while (*dst_ptr)
	{
		dst_ptr++;
		size--;
	}
	while (*src_ptr && size - 1)
	{
		*dst_ptr++ = *src_ptr++;
		size--;
	}
	*dst_ptr = '\0';
	return (dst_len + ft_strlen(src));
}
