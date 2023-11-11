/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmillier <nmillier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:37:45 by ydred             #+#    #+#             */
/*   Updated: 2023/11/11 14:02:51 by nmillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putbase16(unsigned int n, char *base)
{
	char	c[8];
	int		i;
	int		nbr;

	i = 7;
	nbr = n;
	if (nbr != 0)
	{
		while (nbr > 1)
		{
			c[i] = base[nbr % 16];
			nbr /= 16;
			i--;
		}
		c[i] = '\0';
	}
	while (++i <= 7)
		write(1, &c[i], 1);
}

void	ft_putxlower(va_list args)
{
	ft_putbase16(va_arg(args, unsigned int), "0123456789abcdef");
}
