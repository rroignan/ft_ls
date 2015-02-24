/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 17:17:47 by rroignan          #+#    #+#             */
/*   Updated: 2015/02/24 19:28:12 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>
#include "libft.h"

void				lsymb(char *arg)
{
	char			*symb;

	symb = ft_strnew(256);
	readlink(arg, symb, 256);
	ft_putstr(arg);
	ft_putstr(" -> ");
	ft_putendl(symb);
}

char				*ft_adjust(char *time)
{
	int				i;
	int				j;
	char			*cpy;

	i = 0;
	j = 0;
	cpy = ft_strnew(12);
	while (i != 16)
	{
		if (i < 4)
			i++;
		if (i >= 4 && i <= 15)
		{
			cpy[j] = time[i];
			i++;
			j++;
		}
	}
	return (cpy);
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

int					main(int ac, char **av)
{
	char			*ri;
	struct stat		buf;
	struct passwd	*name;
	struct group	*grp;

	ri = ft_strnew(11);
	if (ac == 2)
	{
		lstat(av[1], &buf);
		name = getpwuid(buf.st_uid);
		grp = getgrgid(buf.st_gid);
		ft_putstr_ls(ft_ri(ri, buf.st_mode));
		ft_putnbr(buf.st_nlink);
		ft_putstr(" ");
		ft_putstr_ls(name->pw_name);
		ft_putstr_ls(grp->gr_name);
		ft_putnbr(buf.st_size);
		ft_putstr(" ");
		ft_putstr(ft_adjust(ctime(&(buf.st_mtimespec.tv_sec))));
		ft_putstr(" ");
		(ft_ri(ri, buf.st_mode)[0] == 'l' ? lsymb(av[1]) : ft_putendl(av[1]));
	}
	return (0);
}
