/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmillier <nmillier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:35:12 by ydred             #+#    #+#             */
/*   Updated: 2023/11/11 12:12:48 by nmillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_writepointer(void *ptr, char *base)
{
	unsigned long long	p;
	char				s[18];
	int					i;

	i = 17;
	p = (unsigned long long) ptr;
	if (p != 0)
	{
		while (p >= 1)
		{
			s[i] = base[p % 16];
			p /= 16;
			i--;
		}
		s[i--] = 'x';
		s[i--] = '0';
		while (++i <= 17)
			write(1, &s[i], 1);
	}
	else
		write(1, "0x0", 3);
}

void	ft_putp(va_list args)
{
	void	*p;

	p = va_arg(args, void *);
	ft_writepointer(p, "0123456789abcdef");
}
