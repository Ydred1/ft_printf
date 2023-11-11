/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydred <ydred@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:37:45 by ydred             #+#    #+#             */
/*   Updated: 2023/11/11 22:24:12 by ydred            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_putbase16(unsigned int n, char *base)
{
	char	c[8];
	int		i;
	int		nbr;

	i = 6;
	ft_memset(c, ' ', 8);
	c[i] = '0';
	nbr = n;
	while (nbr > 1)
	{
		c[i] = base[nbr % 16];
		nbr /= 16;
		i--;
	}
	c[i--] = 'x';
	c[i--] = '0';
	return (ft_strtrim(c, " "));
}

char	*ft_putxlower(va_list args)
{
	return(ft_putbase16(va_arg(args, unsigned int), "0123456789abcdef"));
}
