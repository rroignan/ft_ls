/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 21:18:06 by rroignan          #+#    #+#             */
/*   Updated: 2015/03/20 19:07:20 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_l(t_list *list)
{
	//ft_stat(list);
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
}

void	print_list(t_list *list, char *arg)
{
	if (ft_strncmp(arg, "-l", 2) == 0 && arg)
		print_l(list);
	else if (ft_strncmp(arg, "-a", 2) == 0 && arg)
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
	if (tmp)
	{
		tmp->name = str;
		ft_stat(tmp);
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

char	**fill_tab(char **av)
{
	int		i;
	int		r;
	int		f;
	char	**tab;

	i = 0;
	r = 0;
	f = 1;
	while (av[i] && av[i + 1][0] == '-')
		i++;
	if ((tab = (char **)malloc(sizeof(char *) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (av[f][0] == '-')
	{
		tab[r] = ft_strnew(ft_strlen(av[f]));
		ft_strcpy(tab[r], av[f]);
		r++;
		f++;
	}
	tab[r] = '\0';
	return (tab);
}

int		main(int ac, char **av)
{
	flag_l	*flag;
	char 	**tab;
	int		r;

	tab = fill_tab(av);
	flag = ft_check_f(tab);
	/*struct dirent	*library;
	DIR				*dirp;
	t_list			*list;

	list = NULL;
	ac = ac;
	dirp = opendir(av[2]);
	if (dirp == NULL)
	{
		ft_putendl(av[1]);
		return (0);
	}		
	while ((library = readdir(dirp)) != NULL)
		list = add_link(list, library->d_name);
	(list != NULL ? print_list(list, av[1]) : list);
	closedir(dirp);*/
	ac = ac;
	return (0);
}
