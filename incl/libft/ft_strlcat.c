/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 10:06:36 by mbotes            #+#    #+#             */
/*   Updated: 2019/05/21 08:54:33 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	loop;
	size_t	len_dst;
	size_t	len;

	len_dst = ft_strlen((const char *)dst);
	loop = -1;
	len = len_dst;
	if (dstsize < len_dst)
		len = dstsize;
	len = len + ft_strlen(src);
	while ((++loop + len_dst) < (dstsize - 1) && dstsize > 0 && src[loop])
		dst[len_dst + loop] = src[loop];
	dst[len_dst + loop] = '\0';
	return (len);
}
