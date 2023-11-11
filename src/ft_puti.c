/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydred <ydred@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:41:56 by ydred             #+#    #+#             */
/*   Updated: 2023/11/11 21:58:09 by ydred            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

char	*ft_puti(va_list args)
{
	char	c[11];
	int		n;
	int 	i;

	n = va_arg(args, int);
	i = 9;
	ft_memset(c, ' ', 11);
	c[i] = '0';
	while (n > 1)
	{
		c[i] = n % 10 + 48;
		n /= 10;
		i--;
	}
	return (ft_strtrim(c, " "));
}
