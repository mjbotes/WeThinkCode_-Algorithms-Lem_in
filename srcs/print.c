/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:49:02 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/16 07:53:40 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem_in.h"

void	ft_print_routes(t_route *head)
{
	t_route	*ptr;
	t_list	*l;
	t_rooms	*r;

	ptr = head;
	if (ptr)
	{
		l = ptr->route_h;
		while (l)
		{
			r = (t_rooms *)l->content;
			if (l->next && r->name)
			{
				ft_putstr(r->name);
				ft_putstr("  ->  ");
			}
			else
				ft_putendl(r->name);
			l = l->next;
		}
	}
	else
		return ;
	ft_print_routes(head->next);
}

void	ft_print_links(t_rooms *head)
{
	t_rooms *room;
	t_list	*lst;
	t_rooms	*ptr;

	room = head;
	while (room)
	{
		ft_putendl(room->name);
		ft_putnbr(room->start);
		ft_putendl("------");
		lst = room->links;
		while (lst)
		{
			ptr = lst->content;
			ft_putendl(ptr->name);
			lst = lst->next;
		}
		room = room->next;
		ft_putendl("");
	}
}

void	ft_print_ant(int ant, char *name)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(name);
}
