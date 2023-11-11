/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydred <ydred@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:34:19 by ydred             #+#    #+#             */
/*   Updated: 2023/11/12 00:16:24 by ydred            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_puts(va_list args)
{
	char	*string;

	string = (char *)va_arg(args,const char *);
	if (!string)
		return (ft_strdup("nil"));
	return (ft_strdup(string));
}
