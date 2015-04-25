/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 21:18:06 by rroignan          #+#    #+#             */
/*   Updated: 2015/04/25 18:42:27 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_lineup(t_list *list, t_lineup *length)
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
}

int		count_blck(t_list *list, t_flag *flag)
{
	int		bl;

	bl = 0;
	if (flag->a == 0)
	{	
		while (list && list->file[0] == '.')
			list = list->next;
	}
	while (list)
	{
			bl += list->blocks;
			list = list->next;
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
		ft_putstr(str);
		while (i != 0)
		{
			ft_putchar(' ');
			i--;
		}
	}
	else if (ft_strlen(str) == l)
		ft_putstr(str);
}


void	print_l(t_list *list, t_lineup *length, t_flag *flag)
{
	char	*spc;
	int		i;

	spc = NULL;
	i = 0;
	if (list->next)
	{
		ft_putstr("total ");
		ft_putnbr(count_blck(list, flag));
		ft_putchar('\n');
	}
	(void)length;
	if (flag->a == 1)
	{
		while (list)
		{
			ft_putstr(list->mode);
			ft_putstr(" ");
			ft_putnbrsp(list->nblink, length->nblink);
			ft_putstr(" ");
			ft_putspc(list->uid, length->uid);
			ft_putstr("  ");
			ft_putspc(list->group, length->group);
			ft_putstr("  ");
			ft_putnbrsp(list->size, length->size);
			ft_putstr(" ");
			ft_putstr(list->time);
			ft_putstr(" ");
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
				ft_putstr(list->mode);
				ft_putstr(" ");
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
}

void	print_list(t_list *list, t_flag *flag, t_lineup *length)
{
	if (flag->l == 1)
		print_l(list, length, flag);
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

t_list	*add_link(t_list *list, t_flag *flag, char *folder, char *file, t_lineup *length)
{
	t_list	*new;
	t_list	*temp;

	new = malloc(sizeof(t_list));
	ft_bzero(new, sizeof(t_list));
	if (new)
	{
		new->folder = ft_strdup(folder);
		new->file = ft_strdup(file);
		new->path = ft_strjoin(ft_strjoin(new->folder, "/"), new->file);
		ft_stat(new, flag);
		ft_lineup(new, length);
		new->next = NULL;
		if (list == NULL)
			return (new);
		temp = list;
		if (flag->r == 1)
		{
			while (temp && temp->next)
			{
				if (ft_strcmp(new->file, temp->file) == -1 && ft_strcmp(new->file, temp->next->file) == 1)
				{
					new->next = temp->next;
					temp->next = new;
					return (list);
				}
				else if (ft_strcmp(new->file, temp->file) == -1 && ft_strcmp(new->file, temp->next->file) == -1)
					temp = temp->next;
				else if (ft_strcmp(new->file, temp->file) == 1)
				{
					new->next = temp;
					list = new;
					return (list);
				}
			}
			temp->next = new;
		}
		else
		{
			while (temp && temp->next)
			{
				if (ft_strcmp(new->file, temp->file) == 1 && ft_strcmp(new->file, temp->next->file) == -1)
				{
					new->next = temp->next;
					temp->next = new;
					return (list);
				}
				else if (ft_strcmp(new->file, temp->file) == 1 && ft_strcmp(new->file, temp->next->file) == 1)
					temp = temp->next;
				else if (ft_strcmp(new->file, temp->file) == -1)
				{
					new->next = temp;
					list = new;
					return (list);
				}
			}
			temp->next = new;
		}
	}
	return (list);
}

void	ft_ls(char *str, t_flag *flag)
{
	struct dirent	*library;
	DIR				*dirp;
	t_list			*list;
	t_lineup		*length;

	list = NULL;
	dirp = opendir(str);
	length = malloc(sizeof(t_lineup));
	ft_bzero(length, sizeof(t_lineup));
	if (dirp == NULL)
		list = add_link(list, flag, ".", str, length);
	else
	{
		while ((library = readdir(dirp)) != NULL)
			list = add_link(list, flag, str, library->d_name, length);
	}
	(list != NULL ? print_list(list, flag, length) : list);
	if (dirp)
		closedir(dirp);
}

int		main(int ac, char **av)
{
	t_flag			*flag;
	t_file			*file;
	t_folder		*folder
	t_err			*err;
	int				r;
	int				i;

	r = 1;
	i = 0;
	flag = NULL;
	file = NULL;
	folder = NULL;
	err = NULL;
	flag = ft_check_f(av + 1);
	while (av[r])
	{
		if (flag->dm == 1)
		{
			while (av[r][1] != '-')
				r++;
			if (r + 1 == ac)
			{
				ft_ls(".", flag);
				break;
			}
			else
			{	
				r++;
				while (av[r])
				{
					ft_ls(av[r], flag);
					r++;
				}
			}
		}
		else
		{
			while (av[r] && av[r][0] == '-')
				r++;
			if (r == ac)
				ft_ls(".", flag);
			else
			{
				i = r;
				while (av[i])
					i++;
				while (av[r])
				{
					if (i - r - 1 >= 2)
					{
						ft_putendl(ft_strjoin(av[r], ":"));
						ft_otherarg(av + r, file, folder, err, flag);
						ft_ls(av[r], flag);
						ft_putchar('\n');
						r++;
					}
					else
					{
						ft_ls(av[r], flag);
						r++;
					}
				}
			}
		}
	}
	if (ac < 2)
	{
		flag = ft_check_f(av + 1);
		ft_ls(".", flag);
	}
	return (0);
}
