/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:17:18 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/16 08:58:17 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem_in.h"

t_rooms	*ft_find_room(t_rooms **head, char *name)
{
	t_rooms	*ptr;

	ptr = *head;
	while (ptr && !ft_strequ(ptr->name, name))
		ptr = ptr->next;
	if (ptr == NULL)
		ft_error_links(name);
	return (ptr);
}

t_rooms	**ft_add_link(t_rooms **head, char **arr)
{
	t_rooms *r1;
	t_rooms	*r2;

	if (arr[0] != NULL && arr[1] && arr[2] == NULL)
	{
		r1 = ft_find_room(head, arr[0]);
		r2 = ft_find_room(head, arr[1]);
		ft_lstadd(&(r1->links), ft_lstnew(r2, sizeof(r2)));
		ft_lstadd(&(r2->links), ft_lstnew(r1, sizeof(r2)));
	}
	return (head);
}
