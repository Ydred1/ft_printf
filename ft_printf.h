/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydred <ydred@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:52:32 by nmillier          #+#    #+#             */
/*   Updated: 2023/11/11 20:28:55 by ydred            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "lib/libft/libft.h"

typedef char	*(*t_func)(va_list);

int	ft_printf(const char *s, ...);
char	*ft_puti(va_list args);
char	*ft_putpercente(va_list args);
char	*ft_puts(va_list args);
char	*ft_putxlower(va_list args);
char	*ft_putxupper(va_list args);
char	*ft_putbase16(int unsigned nbr, char *base);
char	*ft_putc(va_list args);
char	*ft_putp(va_list args);
char	*ft_putu(va_list args);

#endif