/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmillier <nmillier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:33:24 by ydred             #+#    #+#             */
/*   Updated: 2023/11/12 15:53:03 by nmillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_putc(va_list args)
{
	char	*c;
	char	character;

	character = va_arg(args, int);
	if (!character)
		return ((void *) 0x1);
	c = malloc(2 * sizeof(char));
	if (!c)
		return (NULL);
	c[1] = '\0';
	c[0] = character;
	return (c);
}
