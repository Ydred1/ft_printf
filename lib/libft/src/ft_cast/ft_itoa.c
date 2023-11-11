/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmillier <nmillier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:55:31 by nmillier          #+#    #+#             */
/*   Updated: 2023/11/11 15:12:47 by nmillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	count_char(int n)
{
	int	nb;
	int	digit;

	nb = 0;
	digit = 1000000000;
	if (n < 0)
		nb++;
	if (n == 0)
		return (1);
	while (n / digit % 10 == 0)
		digit /= 10;
	while (digit >= 1)
	{
		nb++;
		digit /= 10;
	}
	return (nb);
}

char	*ft_itoa(int n)
{
	char	*string;
	int		i;
	int		digit;

	string = (char *) malloc((count_char(n) + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	i = 0;
	digit = 1000000000;
	while (n / digit % 10 == 0 && n != 0)
		digit /= 10;
	if (n < 0)
		string[i++] = '-';
	while (digit >= 1 && n != 0)
	{
		if (n < 0)
			string[i++] = ((n / digit % 10) * -1) + 48;
		else
			string[i++] = (n / digit % 10) + 48;
		digit /= 10;
	}
	if (n == 0)
		string[i++] = '0';
	string[i] = '\0';
	return (string);
}
