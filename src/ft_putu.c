/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydred <ydred@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:37:10 by ydred             #+#    #+#             */
/*   Updated: 2023/11/11 22:59:07 by ydred            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_putu(va_list args)
{
	char			c[11];
	int				i;
	unsigned int	nbr;

	i = 10;
	ft_memset(c, ' ', 11);
	nbr = va_arg(args, unsigned int);
	c[i--] = '\0';
	c[i] = '0';
	while (nbr > 1)
	{
		c[i] = nbr % 10 + 48;
		nbr /= 10;
		i--;
	}
	return (ft_strtrim(c, " "));
}
