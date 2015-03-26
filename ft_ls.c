/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 21:18:06 by rroignan          #+#    #+#             */
/*   Updated: 2015/03/26 19:54:46 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_l(t_list *list)
{
	while (list)
	{
		/*if (list->name[0] == '.')
			list = list->next;
		else*/
		{
			ft_stat(list);
			ft_putstr(list->mode);
			ft_putstr("  ");
			ft_putnbr(list->nblink);
			ft_putstr(" ");
			ft_putstr(list->uid);	
			ft_putstr(" ");
			ft_putstr(list->group);
			ft_putstr(" ");
			ft_putnbr(list->size);
			ft_putstr(" ");
			ft_putstr(list->time);
			ft_putstr(" ");
			ft_putendl(list->name);
			list = list->next;
		}
	}
}

void	print_list(t_list *list, flag_l *flag)
{
	if (flag->l == 1)
		print_l(list);
	else if (flag->a == 1)
	{
		while (list)
		{
			ft_putendl(list->name);
			list = list->next;
		}
	}
	else
	{
		while (list)
		{
			if (list->name[0] == '.')
				list = list->next;
			else
			{
				ft_putendl(list->name);
				list = list->next;
			}
		}
	}
}

t_list	*add_link(t_list *list, char *str)
{
	t_list	*tmp;
	t_list	*temp;

	tmp = malloc(sizeof(t_list));
	ft_bzero(tmp, sizeof(t_list));
	if (tmp)
	{
		tmp->name = ft_strdup(str);
		tmp->next = NULL;
	}
	if (list == NULL)
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

int		main(int ac, char **av)
{
	flag_l			*flag;
	struct dirent	*library;
	DIR				*dirp;
	int				r;
	t_list			*list;

	if (ac >= 2)
	{

		flag = ft_check_f(av + 1);
		r = 1;
		if (flag->dm == 1)
		{
			list = NULL;
			while (av[r][1] != '-')
				r++;
			r++;
			while (av[r])
			{
				dirp = opendir(av[r]);
				if (dirp == NULL)
					list = add_link(list, av[r]);
				else
				{
					while ((library = readdir(dirp)) != NULL)
						list = add_link(list, library->d_name);
				}
				r++;
			}
			(list != NULL ? print_list(list, flag) : list);
			closedir(dirp);
		}
		else
		{
			list = NULL;
			while (av[r][0] == '-')
				r++;
			while (av[r])
			{
				dirp = opendir(av[r]);
				if (dirp == NULL)
					list = add_link(list, av[r]);
				else
				{
					while ((library = readdir(dirp)) != NULL)
						list = add_link(list, library->d_name);
				}
				r++;
			}
			(list != NULL ? print_list(list, flag) : list);
			closedir(dirp);
		}
	}
		/*dirp = opendir(".");
		if (dirp == NULL)
		{
			ft_putendl(av[r]);
			return (0);
		}
		while ((library = readdir(dirp)) != NULL)
			list = add_link(list, library->d_name);
		(list != NULL ? print_list(list, av[1]) : list);
		closedir(dirp);
	}*/
	return (0);
}

