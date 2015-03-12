/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 21:18:06 by rroignan          #+#    #+#             */
/*   Updated: 2015/03/12 16:47:56 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_l(t_list *list)
{
	

void	print_list(t_list *list, char *arg)
{
	if (ft_strncmp(arg, "-l", 2) == 0 && arg)
		print_l(list);
	else if (ft_strncmp(arg, "-a", 2) == 0 && arg)
	{
		while (list)
		{
			ft_putendl(list->phr);
			list = list->next;
		}
	}
	else
	{
		while (list)
		{
			if (list->phr[0] == '.')
				list = list->next;
			else
			{
				ft_putendl(list->phr);
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
		tmp->phr = str;
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
	struct dirent	*library;
	DIR				*dirp;
	t_list			*list;

	list = NULL;
	ac = ac;
	dirp = opendir(".");
	/*if (dirp == NULL)
	{
		ft_putendl(av[1]);
		return (0);
	}*/		
	while ((library = readdir(dirp)) != NULL)
		list = add_link(list, library->d_name);
	(list != NULL ? print_list(list, av[1]) : list);
	closedir(dirp);
	return (0);
}
