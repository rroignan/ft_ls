/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 21:18:06 by rroignan          #+#    #+#             */
/*   Updated: 2015/04/10 19:55:19 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_lineup(t_list *list, lineup *length)
{
	if (ft_strlen(ft_itoa(list->nblink)) > length->nblink)
		length->nblink = ft_strlen(ft_itoa(list->nblink));
	if (ft_strlen(list->uid) > length->uid)
		length->uid = ft_strlen(list->uid);
	if (ft_strlen(list->group) > length->group)
		length->group = ft_strlen(list->group);
	if (ft_strlen(ft_itoa(list->size)) > length->size)
		length->size = ft_strlen(ft_itoa(list->size));
	if (ft_strlen(list->time) > length->time)
		length->time = ft_strlen(list->time);
	/*length->size = 51252;
	length->nblink = 12;
	length->time = "ok mois je suis bo";
	length->group ="2014_paris       ldfgkjdfgjdfgdsjhg ";
	length->uid = "rroignan";
	(void)list;*/
}

int		count_blck(t_list *list)
{
	int		bl;

	bl = 0;
	while (list)
	{
		if (list->file[0] == '.')
			list = list->next;
		else
		{
			bl += list->blocks;
			list = list->next;
		}
	}
	return (bl);
}

void	ft_putnbrsp(size_t s, size_t n)
{
	int		i;

	i = 0;
	if (ft_strlen(ft_itoa(s)) < n)
	{
		i = n - ft_strlen(ft_itoa(s));
		while (i != 0)
		{
			ft_putchar(' ');
			i--;
		}
		ft_putnbr(s);
	}
	else
		ft_putnbr(s);
}

void	ft_putspc(char *str, size_t l)
{
	int		i;

	i = 0;
	if (ft_strlen(str) < l)
	{
		i = l - ft_strlen(str);
		while (i != 0)
		{
			ft_putchar(' ');
			i--;
		}
		ft_putstr(str);
	}
	else if (ft_strlen(str) == l)
			ft_putstr(str);
}


void	print_l(t_list *list, lineup *length)
{
	char	*spc;
	int		i;

	spc = NULL;
	i = 0;
	ft_putstr("total ");
	ft_putnbr(count_blck(list));
	ft_putchar('\n');
	(void)length;
	while (list)
	{
		if (list->file[0] == '.')
			list = list->next;
		else
		{
			ft_putstr(list->mode);
			ft_putstr("  ");
				ft_putnbrsp(list->nblink, length->nblink);
			ft_putstr(" ");
				ft_putspc(list->uid, length->uid);
			ft_putstr("  ");
				ft_putspc(list->group, length->group);
			ft_putstr("  ");
				ft_putnbrsp(list->size, length->size);
			ft_putstr(" ");
				ft_putspc(list->time, length->time);
			ft_putstr(" ");
			ft_putendl(list->file);
			list = list->next;
		}
	}
}

void	print_list(t_list *list, flag_l *flag, lineup *length)
{
	if (flag->l == 1)
		print_l(list, length);
	else if (flag->a == 1)
	{
		while (list)
		{
			ft_putendl(list->file);
			list = list->next;
		}
	}
	else
	{
		while (list)
		{
			if (list->file[0] == '.')
				list = list->next;
			else
			{
				ft_putendl(list->file);
				list = list->next;
			}
		}
	}
}

t_list	*add_link(t_list *list, flag_l *flag, char *folder, char *file, lineup *length)
{
	t_list	*tmp;
	t_list	*temp;

	tmp = malloc(sizeof(t_list));
	ft_bzero(tmp, sizeof(t_list));
	if (tmp)
	{
		tmp->folder = ft_strdup(folder);
		tmp->file = ft_strdup(file);
		tmp->path = ft_strjoin(ft_strjoin(tmp->folder, "/"), tmp->file);
		ft_stat(tmp);
		ft_lineup(tmp, length);
		if (flag->r == 1)
			tmp->next = list;
		else
			tmp->next = NULL;
	}
	if (list == NULL || flag->r == 1)
		return (tmp);
	else
	{
		temp = list;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = tmp;
		return (list);
	}
}

void	ft_ls(char *str, flag_l *flag)
{
	struct dirent	*library;
	DIR				*dirp;
	t_list			*list;
	lineup			*length;

	list = NULL;
	dirp = opendir(str);
	length = malloc(sizeof(lineup));
	ft_bzero(length, sizeof(lineup));
	if (dirp == NULL)
	{
		list = add_link(list, flag, str, str, length);
		//ft_stat(list);
		//ft_lineup(list, length);
	}
	else
	{
		while ((library = readdir(dirp)) != NULL)
		{
			list = add_link(list, flag, str, library->d_name, length);
		}
	}
	(list != NULL ? print_list(list, flag, length) : list);
	closedir(dirp);
}

int		main(int ac, char **av)
{
	flag_l			*flag;
	int				r;

	r = 1;
	flag = NULL;
	if (ac >= 2)
	{
		flag = ft_check_f(av + 1);
		if (flag->dm == 1)
		{
			while (av[r][1] != '-')
				r++;
			r++;
			while (av[r])
			{
				ft_ls(av[r], flag);
				r++;
			}
		}
		else
		{
			while (av[r][0] == '-')
				r++;
			while (av[r])
			{
				ft_ls(av[r], flag);
				r++;
			}
		}
	}
	return (0);
}
