/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydred <ydred@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:51:23 by nmillier          #+#    #+#             */
/*   Updated: 2023/11/12 00:18:18 by ydred            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
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

static int new_elemfunc(t_list **lst, t_func func, va_list args)
{
	char	*string;
	t_list	*elem;

	string = func(args);
	elem = ft_lstnew(string);
	if (!string || !elem)
		return (0);
	ft_lstadd_back(lst, elem);
	return (1);
}

static int new_elem(t_list **lst, const char *s)
{
	int		i;
	char	*string;
	t_list	*elem;

	i = 0;
	while (s[i] != '%' && s[i])
		i++;
	string = ft_substr(s, 0, i);
	elem = ft_lstnew(string);
	if (!string || !elem)
		return (0);
	ft_lstadd_back(lst, elem);
	return (i);
}

int	ft_printf(const char *s, ...)
{
	t_func	func[128];
	char	*src;
	int		flag;
	va_list	args;
	t_list	*lst;
	
	src = (char *) s;
	init(func, &flag);
	va_start(args, s);
	lst = NULL;
	while (*src)
	{
		if (flag == 1)
		{
			if (new_elemfunc(&lst, *func[(int) *src], args) == 0)
			{
				ft_lstclear(&lst, free);
				return (0);
			}
			flag = 0;
		}
		else if (flag == 0)
		{
			if (*src != '%')
			{
				flag = new_elem(&lst, src);
				if (!flag)
				{
					ft_lstclear(&lst, free);
					return (0);
				}
				src += flag - 1;
				flag = 0;
			}
			else
				flag = 1;
		}
		src++;
	}
	va_end(args);
	ft_lstwritecontent(&lst, 1);
	ft_lstclear(&lst, free);
	return (1);
}
