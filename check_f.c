/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 12:42:41 by rroignan          #+#    #+#             */
/*   Updated: 2015/03/25 18:55:49 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	idk(char c, flag_l *list)
{
	if (c == 'a' && list->dm == 0)
		list->a = 1;
	else if (c == 'r' && list->dm == 0)
		list->r = 1;
	else if (c == 'R' && list->dm == 0)
		list->R = 1;
	else if (c == 'l' && list->dm == 0)
		list->l = 1;
	else if (c == 't' && list->dm == 0)
		list->t = 1;
	else if (c == '-')
		list->dm = 1;
	else if (!ft_strchr(FLAG, c))
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(c, 2);
		ft_putstr_fd("\nusage: ./ft_ls [-Ralrt] [file ...]\n", 2);
		exit(1);
	}
}

flag_l	*ft_check_f(char **arg)
{
	int		r;
	int		c;
	flag_l	*tab;

	r = 0;
	c = 1;
	if ((tab = (flag_l *)malloc(sizeof(flag_l))) == NULL)
		return (NULL);
	ft_bzero((void *)tab, sizeof(flag_l));
	while (arg[r])
	{
		while (arg[r] && arg[r][c])
		{
			idk(arg[r][c], tab);
			c++;
		}
		c = 1;
		r++;
	}
	return (tab);
}
