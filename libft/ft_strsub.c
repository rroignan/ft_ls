/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 14:57:37 by rroignan          #+#    #+#             */
/*   Updated: 2014/11/26 20:17:55 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = start;
	j = 0;
	if (s)
	{
		if ((str = ft_strnew(len)) == NULL)
			return (NULL);
		while (len > 0)
		{
			str[j] = s[i];
			i++;
			j++;
			len--;
		}
		return (str);
	}
	return (NULL);
}
