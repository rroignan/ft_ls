/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 10:53:14 by rroignan          #+#    #+#             */
/*   Updated: 2015/05/06 14:37:45 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls2.h"

char	*ft_index(char *str)
{
	int				i;
	struct stat		buf;
	
	i = 0;
	i = lstat(ft_strjoin("./", str), &buf);
	if (S_ISCHR(buf))
		return ("d");
	else if (i = 1)
		return (strerror(errno));
	else
		return ("o");
}
