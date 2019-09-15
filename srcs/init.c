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

t_rooms	*ft_init(int fd, t_rooms **head)
{
	char	*str;
	char	**arr;
	char	*comment;

	comment = NULL;
	while (get_next_line(fd, &str) > 0)
	{
		ft_putendl(str);
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
			if (comment)
				ft_strdel(&comment);
		}
		else
			break ;
		ft_free_her(arr);
		ft_strdel(&str);
	}
	head = ft_init_links(head, fd, str);
	if (str)
		ft_strdel(&str);
	if (arr)
		ft_free_her(arr);
	return (*head);
}

t_rooms	**ft_init_links(t_rooms **head,int fd, char *s)
{
	char	*str;
	char	**arr;
	t_rooms	*r;

	if (!(*head) || !(*head)->next || !(*head)->next->next)
		ft_error_room();
	if (ft_strlen(s) > 1)
	{
		arr = ft_strsplit(s, '-');
		head = ft_add_link(head, arr);
		ft_free_her(arr);
	}
	while (get_next_line(fd, &str))
	{
		ft_putendl(str);
		arr = ft_strsplit(str, '-');
		head = ft_add_link(head, arr);
		ft_free_her(arr);
		ft_strdel(&str);
	}
	return (head);
}
