/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydred <ydred@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:33:24 by ydred             #+#    #+#             */
/*   Updated: 2023/11/11 22:13:27 by ydred            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_putc(va_list args)
{
	char	c[2];

	c[1] = '\0';
	c[0] = va_arg(args, int);
	return (ft_strdup(c));
}
