/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmillier <nmillier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:34:19 by ydred             #+#    #+#             */
/*   Updated: 2023/11/11 13:55:28 by nmillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

void	ft_puts(va_list args)
{
	char	*string;

	string = va_arg(args, char *);
	if (string)
		write(1, string, ft_strlen(string));
	else
		write(1, "(nil)", 6);
}
