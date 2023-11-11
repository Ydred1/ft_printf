/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmillier <nmillier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:54:38 by nmillier          #+#    #+#             */
/*   Updated: 2023/11/11 15:12:47 by nmillier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_cw(char const *s, char c, int *start, int *end)
{
	char	*string;
	int		nb;
	int		flag;

	string = (char *)s;
	nb = 0;
	flag = 1;
	*start = 0;
	*end = 0;
	while (*string)
	{
		if (*string == c && flag == 0)
			flag = 1;
		if (*string != c && flag == 1)
		{
			nb++;
			flag = 0;
		}
		string++;
	}
	return (nb);
}

static char	**ft_freetab(char **tab, int current)
{
	while (current >= 0)
		free(tab[current--]);
	free(tab);
	return (NULL);
}

static char	*ft_substrclean(const char *s, unsigned int start, size_t len)
{
	char			*newstring;
	unsigned int	i;

	newstring = (char *) malloc((len + 1) * sizeof(char));
	if (newstring == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		newstring[i] = s[start + i];
		i++;
	}
	newstring[i] = '\0';
	return (newstring);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i[3];

	if (!s)
		return (NULL);
	tab = (char **) malloc((ft_cw(s, c, &i[0], &i[1]) + 1) * sizeof(char **));
	if (tab == NULL)
		return (NULL);
	i[2] = 0;
	while (s[i[0]])
	{
		while ((s[i[0]] == c && s[i[0]]) || i[0] < i[1])
			i[0]++;
		while ((s[i[1]] != c && s[i[1]]) || i[1] < i[0])
			i[1]++;
		if (s[i[0]])
		{
			tab[i[2]++] = ft_substrclean(s, i[0], i[1] - i[0]);
			if (tab[i[2] - 1] == NULL)
				return (ft_freetab(tab, i[2] - 1));
		}
	}
	tab[i[2]] = (char *) NULL;
	return (tab);
}
