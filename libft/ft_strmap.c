/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 10:08:56 by rroignan          #+#    #+#             */
/*   Updated: 2014/11/13 19:18:09 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			str[j] = f(s[j]);
			j++;
		}
	}
	return (str);
}
