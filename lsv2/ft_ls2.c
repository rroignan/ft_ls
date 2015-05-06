/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/25 14:12:46 by rroignan          #+#    #+#             */
/*   Updated: 2015/05/06 10:45:21 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls2.h"

int		main(int ac, char **av)
{
	int			r;
	t_flag		*flag;

	r = 1;
	flag = NULL;
	flag = ft_check_fv2(av + 1);
	if (flag->dm == 1)
	{
		while (av[r] && av[r][0] == '-' && av[r][1] != '-')
			r++;
		r++;
	}
	else
	{
		while (av[r] && av[r][0] == '-')
			r++;
	}
	if (r + 1 == ac)
		ft_lsv2(".", flag);
	else
	{
		while (av[r])
		{
			ft_otherargv2(av[r], flag);
			r++;
		}
	}
	return (0);
}
