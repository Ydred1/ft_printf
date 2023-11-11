/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmillier <nmillier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:12:11 by nmillier          #+#    #+#             */
/*   Updated: 2023/11/08 11:13:28 by nmillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	powten(int b, int e)
{
	while (e-- > 0)
	{
		b *= 10;
	}
	return (b);
}

static int	toint(const char *nptr, int index, int nbrofdigits)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (nbrofdigits > 0)
	{
		nb += powten(nptr[index--] - 48, i++);
		nbrofdigits--;
	}
	return (nb);
}

int	ft_atoi(const char *nptr)
{
	int	nbrofdigits;
	int	isnegative;
	int	i;
	int	nb;

	i = 0;
	isnegative = 1;
	nbrofdigits = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\r'
		|| nptr[i] == '\n' || nptr[i] == '\v' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '-')
		isnegative = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] == '0')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbrofdigits++;
		i++;
	}
	nb = toint(nptr, i - 1, nbrofdigits);
	nb = nb * isnegative;
	return (nb);
}
