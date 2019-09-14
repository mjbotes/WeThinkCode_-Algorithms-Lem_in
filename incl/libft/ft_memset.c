/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 09:40:11 by mbotes            #+#    #+#             */
/*   Updated: 2019/05/21 09:31:33 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	size_t			loop;
	unsigned char	*pr;

	loop = 0;
	pr = (unsigned char*)ptr;
	while (loop < len)
		pr[loop++] = value;
	return (ptr);
}
