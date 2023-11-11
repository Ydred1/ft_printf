/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmillier <nmillier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:37:45 by ydred             #+#    #+#             */
/*   Updated: 2023/11/11 11:34:59 by nmillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

 void	ft_putbase16(int n, char *base)
{
	char	c[9];
	int		i;
	int		nbr;

	i = 8;
	nbr = n;
	if (nbr != 0)
	{
		if (n < 0)
			write(1, (char *) "-", 1);
		while (nbr >= 1 || nbr <= -1)
		{
			if (nbr > 0)
				c[i] = base[nbr % 16];
			else
				c[i] = base[(nbr % 16) * -1];
			nbr /= 16;
			i--;
		}
		c[i] = '\0';
	}
	while (++i <= 8)
		write(1, &c[i], 1);
}

void	ft_putx(va_list args)
{
	int nbr;

	nbr = va_arg(args, int);
	ft_putbase16(nbr, "0123456789abcdef");
}
