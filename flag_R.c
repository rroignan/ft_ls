/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_R.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 18:13:22 by rroignan          #+#    #+#             */
/*   Updated: 2015/03/08 21:33:57 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	struct dirent	*book;
	DIR				*rid;
	//t_list			*leest;

	rid = opendir(".");
	while ((book = readdir(rid)) != NULL)
	{
		if (book->d_name[0] != '.')
		{
			ft_putstr(book->d_name);
			ft_putstr(" ");
		}
	}

	ac = ac;
	av = av;
	return (0);
}	
