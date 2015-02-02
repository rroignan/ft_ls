/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 13:01:21 by rroignan          #+#    #+#             */
/*   Updated: 2014/11/27 17:46:57 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		nbwords(const char *s, char c)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] != c)
				i++;
		}
		if (s[i] == c)
			i++;
	}
	return (j);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		size;
	int		i_word;

	i = 0;
	size = 0;
	i_word = 0;
	if (!(s && c))
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * (nbwords(s, c) + 1))))
		return (NULL);
	while (i == 0 || s[i - 1] != '\0')
	{
		if ((s[i] == c || s[i] == '\0') && size > 0)
		{
			tab[i_word++] = ft_strsub(s, i - size, size);
			size = 0;
		}
		if (s[i] != c)
			size++;
		i++;
	}
	tab[i_word] = '\0';
	return (tab);
}
