/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 10:22:48 by rroignan          #+#    #+#             */
/*   Updated: 2014/11/18 12:19:21 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	ft_memcpy(str, src, len);
	ft_memcpy(dst, str, len);
	return (dst);
}
