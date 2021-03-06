/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 11:43:30 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/16 16:09:09 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem_in.h"

void	ft_init_h(char **arr, t_rooms **head, char **com)
{
	if (ft_isnumber(arr[1]) && ft_isnumber(arr[2]))
	{
		ft_addroom(head, arr[0], NULL);
		ft_set_es(*head, arr[0], *com);
	}
	else
	{
		ft_putendl("CORDINATES ARE NOT VALID");
		exit(0);
	}
	if (*com)
		ft_strdel(com);
}

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
			if (str[1] == '#')
				comment = ft_strdup(str);
			ft_strdel(&str);
			continue ;
		}
		arr = ft_strsplit(str, ' ');
		if (arr[1] != NULL && arr[2] != NULL)
			ft_init_h(arr, head, &comment);
		else
			head = ft_init_links(head, fd, str);
		ft_free_her(arr);
		(comment) ? ft_strdel(&comment) : 0;
		ft_strdel(&str);
	}
	return (*head);
}

t_rooms	**ft_init_links(t_rooms **head, int fd, char *s)
{
	char	*str;
	char	**arr;

	if (!(*head) || !(*head)->next)
		ft_error_room();
	if (s && ft_strlen(s) > 2)
	{
		arr = ft_strsplit(s, '-');
		head = ft_add_link(head, arr);
		ft_free_her(arr);
	}
	while (get_next_line(fd, &str) > 0)
	{
		ft_putendl(str);
		arr = ft_strsplit(str, '-');
		head = ft_add_link(head, arr);
		ft_free_her(arr);
		ft_strdel(&str);
	}
	return (head);
}

t_list	**ft_init_arr(int n)
{
	t_list	**arr;
	int		loop;

	loop = 0;
	arr = malloc(sizeof(t_list *) * (n + 1));
	while (loop <= n)
	{
		arr[loop] = NULL;
		loop++;
	}
	return (arr);
}
