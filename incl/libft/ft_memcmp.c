/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 09:38:08 by mbotes            #+#    #+#             */
/*   Updated: 2019/05/28 07:32:41 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	int				diff;
	size_t			loop;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	loop = 0;
	diff = 0;
	ptr1 = (unsigned char*)str1;
	ptr2 = (unsigned char*)str2;
	while (diff == 0 && loop < n)
	{
		diff = ptr1[loop] - ptr2[loop];
		loop++;
	}
	return (diff);
}
