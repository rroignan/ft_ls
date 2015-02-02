/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 19:19:36 by rroignan          #+#    #+#             */
/*   Updated: 2014/11/27 11:41:59 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (s)
	{
		str = ft_strnew(ft_strlen(s));
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		while (s[i] != '\0')
		{
			str[j] = s[i];
			i++;
			j++;
		}
		j--;
		while (str[j] == ' ' || str[j] == '\t' || str[j] == '\n')
			j--;
		str[j + 1] = '\0';
		return (str);
	}
	return (NULL);
}
