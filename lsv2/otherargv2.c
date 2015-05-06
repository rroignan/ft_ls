/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otherargv2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 10:35:57 by rroignan          #+#    #+#             */
/*   Updated: 2015/05/06 16:19:03 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls2.h"



void	ft_otherargv2(char *str, t_flag *flag)
{
	t_file		*file;
	t_folder	*folder;
	t_err		*err;

	if (ft_index(str, flag) == "d")
		folder = add_link(folder, flag, str);
	else if (ft_index(str, flag) == "o")
		file = add_link(file, flag, str);
	else
		err = add_linkerr(err, str);
}
