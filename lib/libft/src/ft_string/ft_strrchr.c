/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydred <ydred@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:03:03 by nmillier          #+#    #+#             */
/*   Updated: 2023/11/03 20:24:01 by ydred            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	tosearch;
	int		index;

	ptr = 0;
	index = 0;
	tosearch = (char) c;
	while (s[index])
	{
		if (s[index] == tosearch)
		{
			ptr = (char *) s + index;
		}
		index++;
	}
	if (s[index] == tosearch)
	{
		ptr = (char *) s + index;
	}
	return (ptr);
}
