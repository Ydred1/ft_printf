/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydred <ydred@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:35:12 by ydred             #+#    #+#             */
/*   Updated: 2023/11/11 22:14:56 by ydred            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*ft_writepointer(void *ptr, char *base)
{
	unsigned long long	p;
	char				c[19];
	int					i;

	i = 17;
	ft_memset(c, ' ', 19);
	c[18] = '\0';
	p = (unsigned long long) ptr;
	if (p != 0)
	{
		while (p >= 1)
		{
			c[i] = base[p % 16];
			p /= 16;
			i--;
		}
		c[i--] = 'x';
		c[i--] = '0';
		return (ft_strtrim(c, " "));
	}
	else
		return ("0x0");
}

char	*ft_putp(va_list args)
{
	void	*p;

	p = va_arg(args, void *);
	return (ft_writepointer(p, "0123456789abcdef"));
}
