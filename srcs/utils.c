/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 09:02:58 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/16 14:04:44 by mbotes           ###   ########.fr       */
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

void	ft_putcolor(int i)
{
	if (i == 1)
		ft_putstr("\e[1;32m");
	else if (i == 2)
		ft_putstr("\e[1;33m");
	else if (i == 3)
		ft_putstr("\e[1;34m");
	else if (i == 4)
		ft_putstr("\e[1;35m");
	else if (i == 5)
		ft_putstr("\e[1;36m");
	else if (i == 6)
		ft_putstr("\e[1;37m");
	else if (i == 7)
		ft_putstr("\e[1;38m");
	else if (i == 8)
		ft_putstr("\e[1;39m");
	else if (i == 9)
		ft_putstr("\e[1;31m");
	else if (i == 0)
		ft_putstr("\e[1;30m");
}
