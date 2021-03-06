/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 10:41:02 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/16 12:43:25 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem_in.h"

int		ft_check_routes(t_route *head, t_rooms *room)
{
	t_route	*r_ptr;
	t_list	*links;
	t_rooms	*ptr;

	r_ptr = head;
	links = r_ptr->route_h;
	while (links)
	{
		ptr = links->content;
		if (ptr == room)
			return (0);
		links = links->next;
	}
	return (1);
}

t_route	*ft_route_finder(t_rooms *rooms)
{
	t_route	*new;
	t_rooms	*ptr;
	t_list	*lst;

	ptr = rooms;
	while (ptr && !ptr->start)
		ptr = ptr->next;
	if (ptr == NULL)
		ft_error_start();
	lst = ft_lstnew(ptr, sizeof(ptr));
	new = ft_new_route(lst);
	ft_route_stepper(&new);
	return (new);
}

void	ft_route_stepper_d(t_route **head, t_route **ptr)
{
	t_route	*next;

	next = (*ptr)->next;
	if (*head == *ptr)
		*head = next;
	ft_delete_route(ptr);
	*ptr = next;
}

void	ft_route_stepper(t_route **head)
{
	t_route	*ptr;
	t_list	*rooms;
	t_rooms	*tmp;

	ptr = *head;
	while (ptr)
	{
		rooms = ptr->route_t;
		tmp = (t_rooms *)rooms->content;
		rooms = tmp->links;
		if (tmp->end != 1)
		{
			while (rooms != NULL)
			{
				tmp = (t_rooms *)rooms->content;
				ft_add_route_step(head, ptr, tmp);
				rooms = rooms->next;
			}
			ft_route_stepper_d(head, &ptr);
		}
		else
			ptr = ptr->next;
	}
}

void	ft_add_route_step(t_route **head, t_route *cur, t_rooms *room)
{
	t_route	*new;
	t_list	*l;

	if (ft_check_routes(cur, room) || room->end == 1)
	{
		new = ft_make_route_dup(cur);
		ft_route_pushback(head, new);
		l = ft_lstnew(room, sizeof(room));
		new->route_t->next = l;
		new->route_t = l;
	}
}
