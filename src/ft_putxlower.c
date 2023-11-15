/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxlower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmillier <nmillier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:37:45 by ydred             #+#    #+#             */
/*   Updated: 2023/11/15 12:54:41 by nmillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_putbase16(unsigned int n, char *base)
{
	char			c[9];
	int				i;
	unsigned int	nbr;

	i = 8;
	ft_memset(c, ' ', 8);
	c[i--] = '\0';
	c[i] = '0';
	nbr = n;
	while (nbr >= 1)
	{
		c[i] = base[nbr % 16];
		nbr /= 16;
		i--;
	}
	return (ft_strtrim(c, " "));
}

char	*ft_putxlower(va_list args)
{
	return (ft_putbase16(va_arg(args, unsigned int), "0123456789abcdef"));
}
