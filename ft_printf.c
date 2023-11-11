/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmillier <nmillier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:51:23 by nmillier          #+#    #+#             */
/*   Updated: 2023/11/11 12:38:17 by nmillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_printf(const char *s, ...)
{
	void 	(*func[128])(va_list);
	char	*src;
	int		flag;
	va_list	args;

	src = (char *) s;
	func['i'] = ft_puti;
	func['s'] = ft_puts;
	func['%'] = ft_putpercente;
	func['x'] = ft_putx;
	func['X'] = ft_putX;
	func['c'] = ft_putc;
	func['p'] = ft_putp;
	func['d'] = ft_puti;
	func['u'] = ft_putu;
	va_start(args, s);
	flag = 0;
	while(*src)
	{
		if (flag == 1)
		{
			(*func[(int) *src])(args);
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