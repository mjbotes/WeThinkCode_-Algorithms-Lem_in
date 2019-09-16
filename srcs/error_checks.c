/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:03:26 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/16 12:52:12 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem_in.h"

void	ft_check_rooms(t_rooms *head)
{
	t_rooms	*ptr;
	int		s;
	int		e;

	s = 0;
	e = 0;
	ptr = head;
	while (ptr)
	{
		if (ptr->start)
			s++;
		if (ptr->end)
			e++;
		ptr = ptr->next;
	}
	if (s != 1 || e != 1)
		ft_error_room();
}

void	ft_check_if_ends(t_route *paths)
{
	t_rooms	*r;
	t_route	*p;
	int		e;

	p = paths;
	e = 0;
	while (p)
	{
		r = p->route_t->content;
		if (r->end == 1)
			e = 1;
		p = p->next;
	}
	if (!e)
	{
		ft_putendl("NO POSSIBLE PATH");
		exit(0);
	}
}
