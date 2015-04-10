/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 15:36:51 by rroignan          #+#    #+#             */
/*   Updated: 2015/04/10 20:04:36 by rroignan         ###   ########.fr       */
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
# define FLAG "altRr-"

typedef struct 			s_list
{
	char			*folder;
	char			*file;
	char			*path;
	int				blocks;
	char			*group;
	char			*mode;
	int				nblink;
	int				size;
	char			*time;
	char			*uid;
	struct s_list	*next;
}						t_list;

typedef struct		f_list
{
	int		a;
	int		r;
	int		R;
	int		l;
	int		t;
	int		dm;
}					flag_l;

typedef struct		l_list
{
	size_t		nblink;
	size_t		uid;
	size_t		group;
	size_t		size;
	size_t		time;
}					lineup;

void	ft_stat(t_list *list);
flag_l	*ft_check_f(char **arg);

#endif
