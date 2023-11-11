/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmillier <nmillier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:52:32 by nmillier          #+#    #+#             */
/*   Updated: 2023/11/11 12:31:23 by nmillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	ft_printf(const char *, ...);
void	ft_puti(va_list);
void	ft_putpercente(va_list);
void	ft_puts(va_list);
void	ft_putx(va_list);
void	ft_putX(va_list);
void	ft_putbase16(int, char *);
void	ft_putc(va_list);
void	ft_putp(va_list);
void	ft_putu(va_list);

#endif