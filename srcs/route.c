/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 09:33:29 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/16 08:57:05 by mbotes           ###   ########.fr       */
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
	new_r->next = NULL;
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
	return (new);
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
	return (new);
}

void	ft_delete_route(t_route **ptr)
{
	t_list	*lst;
	t_list	*next;

	if (*ptr && (*ptr)->prev != NULL)
		(*ptr)->prev->next = (*ptr)->next;
	if (*ptr && (*ptr)->next != NULL)
		(*ptr)->next->prev = (*ptr)->prev;
	lst = (*ptr)->route_h;
	while (lst)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
	(*ptr)->route_t = NULL;
	(*ptr)->next = NULL;
	(*ptr)->size = 0;
	free(*ptr);
}

void	ft_delete_routes(t_route **head)
{
	t_list	*lst;
	t_list	*next;

	if (*head)
	{
		ft_delete_routes(&(*head)->next);
		(*head)->next = NULL;
		lst = (*head)->route_h;
		while (lst)
		{
			next = lst->next;
			free(lst);
			lst = next;
		}
		free(*head);
		*head = NULL;
	}
}
