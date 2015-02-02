/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:42:56 by rroignan          #+#    #+#             */
/*   Updated: 2014/11/13 12:59:41 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	if (str1 && str2)
	{
		while ((str1[i] == str2[i]) && (str1[i] != '\0'))
			i++;
		if (str1[i] == str2[i])
			return (1);
		else if (str1 == 0 && str2 == 0)
			return (1);
	}
	return (0);
}
