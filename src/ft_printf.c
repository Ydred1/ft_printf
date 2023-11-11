/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmillier <nmillier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:51:23 by nmillier          #+#    #+#             */
/*   Updated: 2023/11/11 13:53:59 by nmillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	init(t_func *func, int *flag)
{
	func['i'] = ft_puti;
	func['s'] = ft_puts;
	func['%'] = ft_putpercente;
	func['x'] = ft_putxlower;
	func['X'] = ft_putxupper;
	func['c'] = ft_putc;
	func['p'] = ft_putp;
	func['d'] = ft_puti;
	func['u'] = ft_putu;
	*flag = 0;
}

void	ft_printf(const char *s, ...)
{
	t_func	func[128];
	char	*src;
	int		flag;
	va_list	args;

	src = (char *) s;
	init(func, &flag);
	va_start(args, s);
	while (*src)
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
