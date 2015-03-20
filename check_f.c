/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 12:42:41 by rroignan          #+#    #+#             */
/*   Updated: 2015/03/20 19:07:17 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

flag_l	*ft_check_f(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{

	while (s[i] != '\0')
	{
		if (s[i] == 'a')
			list->a = 1;
		else if (s[i] == 'r')
			list->r = 1;
		else if (s[i] == 'R')
			list->R = 1;
		else if (s[i] == 'l')
			list->l = 1;
		else if (s[i] == 't')
			list->t = 1;
	}
	return (list);
}
