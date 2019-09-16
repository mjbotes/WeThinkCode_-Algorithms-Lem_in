/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 09:02:58 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/16 11:10:52 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem_in.h"

void	ft_del_list(void *c, size_t s)
{
	c = NULL;
	s = 0;
	ft_memdel(&c);
}

void	ft_route_thinner_h(t_route **r_ptr, t_list **t_ptr)
{
	t_route	*del;

	del = *r_ptr;
	*r_ptr = (*r_ptr)->next;
	*t_ptr = NULL;
	if (*r_ptr)
		*t_ptr = (*r_ptr)->route_h;
	ft_delete_route(&del);
}

void	ft_route_thinner(t_route *head)
{
	t_route	*r_ptr;
	t_list	*t_ptr;
	t_rooms	*m_ptr;

	r_ptr = head;
	while (r_ptr)
	{
		t_ptr = r_ptr->route_h;
		while (t_ptr)
		{
			m_ptr = t_ptr->content;
			if (m_ptr->used)
			{
				ft_route_thinner_h(&r_ptr, &t_ptr);
				continue ;
			}
			else
				t_ptr = t_ptr->next;
		}
		if (r_ptr)
		{
			ft_set_r_used(r_ptr);
			r_ptr = r_ptr->next;
		}
	}
}

void	ft_set_r_used(t_route *r)
{
	t_list	*l;
	t_rooms	*room;

	l = r->route_h;
	while (l)
	{
		room = l->content;
		if (!(room->start || room->end))
			room->used = 1;
		l = l->next;
	}
}
