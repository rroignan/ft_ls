/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 13:52:56 by rroignan          #+#    #+#             */
/*   Updated: 2014/11/25 20:31:54 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (1);
	else if (s1 && s2)
	{
		while (s1[i] == s2[i] && i < (n - 1) && s1[i] != '\0')
			i++;
		if (s1[i] == s2[i])
			return (1);
	}
	return (0);
}
