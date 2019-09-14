/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 09:35:03 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/14 14:53:51 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem_in.h"

void	ft_addroom(t_rooms **head,char *name, t_list *links)
{
	t_rooms	*new;
	t_rooms	*ptr;

	new = ft_new_room(name, links);
	if (*head == NULL)
		*head = new;
	else
	{
		ptr = *head;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
	ft_putendl(name);
}

int		ft_room_checker(t_rooms *head, char *name)
{
	t_rooms	*ptr;

	ptr = head;
	while (ptr)
	{
		if (ptr->name == name)
			return(0);
		ptr = ptr->next;
	}
	if (head->next)
		if (ft_room_checker(head->next, head->name) == 0)
			return(0);
	return (1);
	
}

t_rooms	*ft_new_room(char *name, t_list *links)
{
	t_rooms	*new;

	new = malloc(sizeof(t_rooms));
	new->name = ft_strdup(name);
	new->links = links;
	new->start = 0;
	new->end = 0;
	new->next = NULL;
	return(new); 
}

void	ft_delete_rooms(t_rooms **head)
{
	if ((*head)->next)
		ft_delete_rooms(&((*head)->next));
	ft_strdel(&(*head)->name);
	ft_lstdel(&(*head)->links, ft_lstdelone);
	*head=NULL;
}

void	ft_set_es(t_rooms *head, char *name, char *c)
{
	int		e;
	int		s;
	t_rooms	*ptr;

	ptr = head;
	e = 0;
	s = 0;
	if (c)
	{
		if (ft_strequ("##start", c))
			s = 1;
		else if (ft_strequ("##end", c))
			e = 1;
	}
	while (ptr && !ft_strequ(ptr->name,name))
		ptr = ptr->next;
	ptr->end = e;
	ptr->start = s;
	//if (c)
	//	ft_strdel(&c);
	c = NULL;
}
