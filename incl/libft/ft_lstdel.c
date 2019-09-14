/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 12:43:06 by mbotes            #+#    #+#             */
/*   Updated: 2019/05/27 15:26:36 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;
	t_list	*next;

	ptr = *alst;
	while (ptr->next != NULL)
	{
		next = ptr->next;
		if (ptr)
			del(ptr, ptr->content_size);
		ptr = next;
	}
	if (ptr != NULL)
		del(ptr, ptr->content_size);
	*alst = NULL;
}
