/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmillier <nmillier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:51:23 by nmillier          #+#    #+#             */
/*   Updated: 2023/11/08 13:37:31 by nmillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

unsigned int count_args(const char *s)
{
	int count;
	char *ptr;

	count = 0;
	ptr = (char *) s;
	while (*ptr)
	{
		if (*ptr == '%' && *(ptr + 1) == '%')
			count++;
		ptr++;
	}
	return (count);
}

void	ft_printf(const char *s, ...)
{
	//va_list lst;
	unsigned int argc;
	(void) s;

	argc = count_args(s);
	//va_start(lst);
	printf("Received %d arguments\n", argc);
	//va_end(lst);
}