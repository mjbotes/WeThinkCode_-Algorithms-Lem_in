/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 12:54:25 by mbotes            #+#    #+#             */
/*   Updated: 2019/05/29 09:15:38 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*ptr;
	t_list	*next;

	ptr = lst;
	if (ptr != NULL || f != NULL)
	{
		while (ptr->next != NULL)
		{
			next = ptr->next;
			f(ptr);
			ptr = next;
		}
		f(ptr);
	}
}
