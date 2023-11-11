/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmillier <nmillier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:02:58 by nmillier          #+#    #+#             */
/*   Updated: 2023/11/11 14:25:44 by nmillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	char 	*p = NULL;
	unsigned int i = 4000000000;

	ft_printf("bonsoir %i %i %i %i %s %x %X %c prout\n%p\n %d %u", 2, 5, 1, 9, p, 255, 255, '\0', p, 234786, i);
	printf(" %s", p);
	return (0);
}
