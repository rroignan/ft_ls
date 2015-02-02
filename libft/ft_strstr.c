/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:48:07 by rroignan          #+#    #+#             */
/*   Updated: 2014/11/26 19:05:55 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	k;
	char	*str;

	k = ft_strlen(s2);
	str = (char *)s1;
	if (*s2 == 0)
		return (str);
	while (*str)
	{
		if (ft_strncmp(str, s2, k) == 0)
			return (str);
		str++;
	}
	return (NULL);
}
