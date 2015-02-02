/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:17:35 by rroignan          #+#    #+#             */
/*   Updated: 2014/11/07 18:02:29 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = dst;
	s2 = (unsigned char *)src;
	while (i < n)
	{
		if (s2[i] == (unsigned char)c)
		{
			s1[i] = s2[i];
			return (&(s1[i + 1]));
		}
		s1[i] = s2[i];
		i++;
	}
	return (NULL);
}
