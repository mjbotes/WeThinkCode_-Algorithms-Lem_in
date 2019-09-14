/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 11:43:30 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/14 15:45:26 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem_in.h"

void	ft_init(int fd, t_rooms **head)
{
	char	*str;
	char	**arr;
	char	*comment;

	while (get_next_line(fd, &str) > 0)
	{
		if (str[0] == '#')
		{
			comment = str;
			continue ;
		}
		arr = ft_strsplit(str, ' ');
		if (arr[1] != NULL && arr[2] != NULL)
		{
			ft_addroom(head, arr[0], NULL);
			ft_set_es(*head, arr[0],comment);
		}
		else
			break ;
		ft_free_her(arr);
	}
	ft_init_links(head, fd, str);
}

void	ft_init_links(t_rooms **head,int fd, char *s)
{
	char	*str;
	char	**arr;

	arr = ft_strsplit(s, '-');
	ft_add_link(head, arr);
	while (get_next_line(fd, &str))
	{
		arr = ft_strsplit(str, '-');
		ft_add_link(head, arr);
		ft_free_her(arr);
		ft_strdel(&str);
	}
}
