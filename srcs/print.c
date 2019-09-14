/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:49:02 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/14 15:31:43 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem_in.h"

void	ft_print_routes(t_route *head)
{
	t_route	*ptr;
	t_list	*l;
	t_rooms	*r;

	ptr = head;
	while (ptr)
	{
		l = ptr->route_h;
		while (l)
		{
			r = (t_rooms *)l->content;
			if (l->next && r->name)
			{
				ft_putstr(r->name);
				ft_putstr(" -> ");
			}
			else if (r->name)
				ft_putendl(r->name);
			l = l->next;
		}
		ptr = ptr->next;
	}
}
