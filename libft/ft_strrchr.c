/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:43:35 by rroignan          #+#    #+#             */
/*   Updated: 2014/11/25 16:26:39 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	if (s)
	{
		i = ft_strlen(str);
		if (c == 0)
			return (&str[i]);
		while (str[i] != c && i > 0)
		{
			i--;
			if (str[i] == (char)c)
				return (&str[i]);
		}
	}
	return (NULL);
}
