/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 11:17:08 by rroignan          #+#    #+#             */
/*   Updated: 2014/11/13 19:13:27 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		j;
	char	*str;

	j = 0;
	str = NULL;
	if (s != NULL && f != NULL)
	{
		if ((str = (char *)malloc(sizeof((*str) * (ft_strlen(s))))) == NULL)
			return (NULL);
		while (s[j])
		{
			str[j] = f(j, s[j]);
			j++;
		}
	}
	return (str);
}
