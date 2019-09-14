/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 09:37:11 by mbotes            #+#    #+#             */
/*   Updated: 2019/05/21 10:20:18 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	size_t			loop;
	unsigned char	*ptr;
	unsigned char	find;

	loop = 0;
	find = (unsigned char)c;
	ptr = (unsigned char*)str;
	while (loop < len)
		if (ptr[loop++] == find)
			return ((unsigned char*)&ptr[loop - 1]);
	return (NULL);
}
