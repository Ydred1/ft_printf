/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmillier <nmillier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:41:56 by ydred             #+#    #+#             */
/*   Updated: 2023/11/12 13:38:33 by nmillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

char	*ft_puti(va_list args)
{
	char	c[12];
	int		n;
	int		i;
	int		nbr;

	n = va_arg(args, int);
	nbr = n;
	i = 10;
	ft_memset(c, ' ', 12);
	c[11] = '\0';
	c[i] = '0';
	while (n >= 1 || n <= -1)
	{
		if (nbr < 0)
			c[i] = (n % 10) * -1 + 48;
		else
			c[i] = n % 10 + 48;
		n /= 10;
		i--;
	}
	if (nbr < 0)
		c[i] = '-';
	return (ft_strtrim(c, " "));
}
