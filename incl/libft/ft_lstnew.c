/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 12:09:33 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/14 11:28:28 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	const *content, size_t content_size)
{
	t_list *new;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if ((new->content = ft_strdup(content)) == NULL)
			return (NULL);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}

t_list	*ft_lstdup(t_list *head)
{
	t_list	*new;
	t_list	*ptr;

	ptr = head;
	new = NULL;
	while (ptr)
	{
		ft_lstadd(&new, ft_lstnew(ptr->content, ptr->content_size));
		ptr = ptr->next;
	}
	return (new);
}
