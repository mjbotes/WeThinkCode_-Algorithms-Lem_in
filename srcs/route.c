/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 09:33:29 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/14 15:44:09 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem_in.h"

void	ft_route_pushback(t_route **head, t_route *new_r)
{
	t_route	*ptr;

	ptr = *head;
	if (*head == NULL)
	{
		*head = new_r;
		return ;
	}
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new_r;
	new_r->prev = ptr;
}

t_route	*ft_make_route_dup(t_route *src)
{
	t_route	*new;
	t_list	*ptr;

	new = malloc(sizeof(t_route));
	new->size = src->size;
	new->next = NULL;
	new->prev = NULL;
	new->route_h = ft_lstdup(src->route_h);
	ptr = new->route_h;
	while (ptr && ptr->next)
		ptr = ptr->next;
	new->route_t = ptr;
	return(new);
}

t_route	*ft_new_route(t_list *list)
{
	t_route	*new;
	t_list	*ptr;

	new = malloc(sizeof(t_route));
	new->route_h = list;
	new->size = 1;
	ptr = new->route_h;
	while (ptr && ptr->next)
	{
		ptr = ptr->next;
		new->size++;
	}
	new->route_t = ptr;
	new->next = NULL;
	new->prev = NULL;
	return(new);
}

void	ft_delete_route(t_route **ptr)
{
	if ((*ptr)->prev && (*ptr)->next)
		(*ptr)->prev->next = (*ptr)->next;
	if ((*ptr)->next != NULL && (*ptr)->prev)
		(*ptr)->next->prev = (*ptr)->prev;
	ft_putendl("hi");
	ft_lstdel(&(*ptr)->route_h, ft_del_list);
	(*ptr)->route_t = NULL;
	(*ptr)->size = 0;
	//ft_memdel((void **)ptr);
}
