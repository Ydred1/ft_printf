/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydred <ydred@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:50:40 by nmillier          #+#    #+#             */
/*   Updated: 2023/11/03 20:19:42 by ydred            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	tosearch;
	int		index;

	ptr = 0;
	index = 0;
	tosearch = (char) c;
	while (s[index] && ptr == 0)
	{
		if (s[index] == tosearch)
		{
			ptr = (char *) s + index;
		}
		index++;
	}
	if (s[index] == tosearch && ptr == 0)
	{
		ptr = (char *) s + index;
	}
	return (ptr);
}
