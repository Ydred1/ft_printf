/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydred <ydred@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:51:23 by nmillier          #+#    #+#             */
/*   Updated: 2023/11/09 20:34:27 by ydred            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_printf(const char *s, ...)
{
	void 	(*map[128])(va_list);
	char	*src;
	int		flag;
	va_list	args;

	src = (char *) s;
	map[105] = ft_puti;
	map[115] = ft_puts;
	map[37] = ft_putpercente;
	map[120] = ft_putx;
	map[88] = ft_putX;
	va_start(args, s);
	flag = 0;
	while(*src)
	{
		if (flag == 1)
		{
			(*map[(int) *src])(args);
			flag = 0;
		}
		else if (flag == 0)
		{
			if (*src == '%')
				flag = 1;
			else
				write(1, src, 1);
		}
		src++;
	}
	va_end(args);
}