/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmillier <nmillier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:51:23 by nmillier          #+#    #+#             */
/*   Updated: 2023/11/11 11:59:54 by nmillier         ###   ########.fr       */
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
	func[105] = ft_puti;
	func[115] = ft_puts;
	func[37] = ft_putpercente;
	func[120] = ft_putx;
	func[88] = ft_putX;
	func[99] = ft_putc;
	func[112] = ft_putp;
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