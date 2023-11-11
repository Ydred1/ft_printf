/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydred <ydred@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:02:58 by nmillier          #+#    #+#             */
/*   Updated: 2023/11/12 00:21:11 by ydred            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	char 	*p = {"bonsoir"};
	unsigned int i = 4000000000;

	ft_printf("bonsoir %i %i %i %i %s %x %X %c prout%p %d %u\n", 2, 5, 1, 9, "bonsoir", 255, 255, '\0', p, 234786, i);
	   printf("bonsoir %i %i %i %i %s %x %X %c prout%p %d %u\n", 2, 5, 1, 9, "bonsoir", 255, 255, '\0', p, 234786, i);
	return (0);
}
