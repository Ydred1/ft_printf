/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydred <ydred@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:52:32 by nmillier          #+#    #+#             */
/*   Updated: 2023/11/09 20:30:30 by ydred            ###   ########.fr       */
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

#endif