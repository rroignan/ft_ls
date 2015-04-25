/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 15:36:51 by rroignan          #+#    #+#             */
/*   Updated: 2015/04/21 21:17:04 by rroignan         ###   ########.fr       */
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
	const time_t	*clock;
	char			*uid;
	struct s_list	*next;
}						t_list;

typedef struct			s_flag
{
	int		a;
	int		r;
	int		R;
	int		l;
	int		t;
	int		dm;
}						t_flag;

typedef struct			s_file
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
	const time_t	*clock;
	char			*uid;
	struct s_file	*next;
}						t_file;

typedef struct			s_folder
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
	const time_t	*clock;
	char			*uid;
	struct s_folder	*next;
}						t_folder;	

typedef struct			s_err
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
	const time_t	*clock;
	char			*uid;
	struct s_err	*next;
}						t_err;

typedef struct		s_lineup
{
	size_t		nblink;
	size_t		uid;
	size_t		group;
	size_t		size;
	size_t		time;
}					t_lineup;

void	ft_stat(t_list *list, t_flag *flag);
t_flag	*ft_check_f(char **arg);
char	**ft_otherarg(char **arg, t_arg *stru);

#endif
