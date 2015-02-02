/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 13:15:21 by rroignan          #+#    #+#             */
/*   Updated: 2014/11/25 14:33:59 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	k;
	char	*str;
	size_t	i;

	k = ft_strlen(s2);
	str = (char *)s1;
	i = 0;
	if (*s2 == 0)
		return (str);
	while (*str && i <= (n - k) && (n >= k))
	{
		if (ft_strncmp(str, s2, k) == 0)
			return (str);
		i++;
		str++;
	}
	return (NULL);
}
