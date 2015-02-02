/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 18:22:12 by rroignan          #+#    #+#             */
/*   Updated: 2015/02/02 13:56:15 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_negative(int *j, int *k)
{
	*j = 1;
	*k = *k * -1;
}

static int		str_size(int n)
{
	int			i;

	i = 0;
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char			*ft_itoa(int c)
{
	char		*str;
	char		*ret;
	int			neg;
	int			i;

	neg = 0;
	if (c == 0)
		return ("0");
	else if (c < 0 && c != -2147483648)
		ft_negative(&neg, &c);
	if (c == -2147483648)
	{
		ret = ft_strdup("-2147483648");
		return (ret);
	}
	i = str_size(c) + neg;
	str = ft_strnew(i);
	(neg == 1 ? str[0] = '-' : str[0]);
	while (c > 0)
	{
		i--;
		str[i] = (c % 10 + 48);
		c = c / 10;
	}
	return (str);
}
