/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmillier <nmillier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:41:56 by ydred             #+#    #+#             */
/*   Updated: 2023/11/11 13:56:14 by nmillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puti(va_list args)
{
	char	c;
	int		n;
	int		digit;

	n = va_arg(args, int);
	digit = 1000000000;
	if (n != 0)
	{
		while (n / digit % 10 == 0)
			digit /= 10;
		if (n < 0)
			write(1, (char *) "-", 1);
		while (digit >= 1)
		{
			if (n < 0)
				c = ((n / digit % 10) * -1) + 48;
			else
				c = (n / digit % 10) + 48;
			digit /= 10;
			write(1, &c, 1);
		}
	}
	else
		write(1, "0", 1);
}
