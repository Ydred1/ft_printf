/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmillier <nmillier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:37:10 by ydred             #+#    #+#             */
/*   Updated: 2023/11/11 12:50:20 by nmillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putu(va_list args)
{
	char			c[9];
	int				i;
	unsigned int	nbr;

	i = 8;
	nbr = va_arg(args, unsigned int);
	while (nbr > 1)
	{
		c[i] = nbr % 10 + 48;
		nbr /= 10;
		i--;
	}
	c[i] = '\0';
	while (++i <= 8)
		write(1, &c[i], 1);
}
