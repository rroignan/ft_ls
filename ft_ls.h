/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 15:36:51 by rroignan          #+#    #+#             */
/*   Updated: 2015/03/12 16:51:24 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <string.h>
# include <dirent.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/types.h>
# include <time.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include "libft.h"

typedef struct 			s_list
{
	char			*name;
	char			*group;
	char			*mode;
	int				nblink;
	int				size;
	char			*time;
	char			*uid;
}

	
	struct s_list	*next;
}						t_list;

typedes struct		f_list
{
	int		a;
	int		r;
	int		R;
	int		l;
	int		t;
}					flag_l;

#endif
