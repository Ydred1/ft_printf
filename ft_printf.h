/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmillier <nmillier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:52:32 by nmillier          #+#    #+#             */
/*   Updated: 2023/11/11 13:57:56 by nmillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef void	(*t_func)(va_list);

void	ft_printf(const char *s, ...);
void	ft_puti(va_list args);
void	ft_putpercente(va_list args);
void	ft_puts(va_list args);
void	ft_putxlower(va_list args);
void	ft_putxupper(va_list args);
void	ft_putbase16(int nbr, char *base);
void	ft_putc(va_list args);
void	ft_putp(va_list args);
void	ft_putu(va_list args);

#endif