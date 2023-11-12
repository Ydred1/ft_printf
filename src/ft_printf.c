/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmillier <nmillier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:51:23 by nmillier          #+#    #+#             */
/*   Updated: 2023/11/12 18:21:03 by nmillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

static void	init(t_func *func, int *flag, char **src, const char *s)
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
	*src = (char *)(s - 1);
	*flag = 0;
}

static char	*new_elem(t_list **lst, t_func func, va_list args, char *s)
{
	int		i;
	char	*string;
	t_list	*elem;

	i = 0;
	if (func == NULL)
	{
		while (s[i] != '%' && s[i])
			i++;
		string = ft_substr(s, 0, i);
	}
	else
		string = func(args);
	elem = ft_lstnew(string);
	if (!string || !elem)
		return (0);
	ft_lstadd_back(lst, elem);
	return (s + i - 1);
}

static int	ft_failedmalloc(t_list *lst)
{
	ft_lstclear(&lst, free);
	return (0);
}

int	ft_printf(const char *s, ...)
{
	t_func	func[128];
	char	*src;
	int		flag;
	va_list	args;
	t_list	*lst;

	init(func, &flag, &src, s);
	va_start(args, s);
	lst = NULL;
	while (*(++src))
	{
		if (*src++ != '%')
		{
			src = new_elem(&lst, NULL, args, --src);
			if (!src)
				return (ft_failedmalloc(lst));
		}
		else
			if (new_elem(&lst, func[(int) *src], args, src) == 0)
				return (ft_failedmalloc(lst));
	}
	va_end(args);
	flag = ft_lstwritecontent(&lst, 1);
	ft_lstclear(&lst, free);
	return (flag);
}
