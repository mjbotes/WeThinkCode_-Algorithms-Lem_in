/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 13:13:04 by mbotes            #+#    #+#             */
/*   Updated: 2019/05/23 13:52:18 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	ptr_dst = (unsigned char*)dst;
	ptr_src = (unsigned char*)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (ptr_dst > ptr_src)
		while (len--)
			ptr_dst[len] = ptr_src[len];
	else
		dst = ft_memcpy(dst, src, len);
	return (dst);
}
