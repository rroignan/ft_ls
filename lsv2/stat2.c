/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 17:17:47 by rroignan          #+#    #+#             */
/*   Updated: 2015/04/25 18:42:24 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


char				*ft_adjust(char *time, int old)
{
	int			i;
	int			j;
	char		*cpy;
	char		*month;
	char		*hour;

	i = 0;
	j = 0;
	cpy = ft_strnew(12);
	month = ft_strnew(3);
	hour = ft_strnew(6);
	if (old == 1)
	{
		month = ft_strsub(time, 4, 4);
		cpy = ft_strsub(time, 8, 3);
		cpy = ft_strjoin(cpy, month);
		cpy = ft_strjoin(cpy, ft_strsub(time, 19, 5));
	}
	else 
	{
		month = ft_strsub(time, 4, 4);
		cpy = ft_strsub(time, 8, 3);
		cpy = ft_strjoin(cpy, month);
		hour = ft_strsub(time, 11, 5);
		cpy = ft_strjoin(cpy, hour);
	}
	return (cpy);
}

char				*ft_time(struct stat buf)
{
	time_t			now;
	time_t			tmps;
	int				old;

	now = time(NULL);
	tmps = buf.st_mtimespec.tv_sec;
	old = 0;
	if (tmps < (now - 15778463) || tmps > (now + 15778463))
	{
		old = 1;
		return (ft_adjust(ctime(&(buf.st_mtimespec.tv_sec)), old));
	}
	return (ft_adjust(ctime(&(buf.st_mtimespec.tv_sec)), old));
}

	
static char			ft_type(mode_t buf)
{
	if (S_ISREG(buf))
		return ('-');
	else if (S_ISDIR(buf))
		return ('d');
	else if (S_ISCHR(buf))
		return ('c');
	else if (S_ISBLK(buf))
		return ('b');
	else if (S_ISFIFO(buf))
		return ('p');
	else if (S_ISLNK(buf))
		return ('l');
	else if (S_ISSOCK(buf))
		return ('s');
	else if (S_ISWHT(buf))
		return ('w');
	else
		return ('?');
}

static char			*ft_ri(char *str, mode_t buf)
{
	str[0] = ft_type(buf);
	str[1] = buf & S_IRUSR ? 'r' : '-';
	str[2] = buf & S_IWUSR ? 'w' : '-';
	str[3] = buf & S_IXUSR ? 'x' : '-';
	str[4] = buf & S_IRGRP ? 'r' : '-';
	str[5] = buf & S_IWGRP ? 'w' : '-';
	str[6] = buf & S_IXGRP ? 'x' : '-';
	str[7] = buf & S_IROTH ? 'r' : '-';
	str[8] = buf & S_IWOTH ? 'w' : '-';
	str[9] = buf & S_IXOTH ? 'x' : '-';
	str[10] = '\0';
	return (str);
}

char				*ft_lsymb(char *arg)
{
	char			*symb;

	symb = ft_strnew(256);
	readlink(arg, symb, 256);
	arg = ft_strjoin(arg, ft_strjoin(" -> ", symb));
	return (arg);
}

void				ft_stat(char *list, t_flag *flag)
{
	char			*ri;
	struct stat		buf;
	struct passwd	*uid;
	struct group	*grp;

	ri = ft_strnew(11);
	lstat(list->path, &buf);
	uid = getpwuid(buf.st_uid);
	grp = getgrgid(buf.st_gid);
	list->mode = ft_ri(ri, buf.st_mode);
	if (ri[0] == 'l' && flag->l == 1)
		list->file = ft_lsymb(list->file);
	list->nblink = buf.st_nlink;
	list->uid = ft_strdup(uid->pw_name);
	list->group = ft_strdup(grp->gr_name);
	list->size = (int)buf.st_size;
	list->time = ft_time(buf);
	list->clock = &(buf.st_mtimespec.tv_sec);
	list->blocks = buf.st_blocks;
}
