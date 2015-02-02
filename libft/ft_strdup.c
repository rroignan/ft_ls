/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 09:39:12 by rroignan          #+#    #+#             */
/*   Updated: 2014/11/10 18:30:24 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		size;

	size = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (size + 1));
	ft_strcpy(str, s1);
	return (str);
}
