/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 09:45:22 by mbotes            #+#    #+#             */
/*   Updated: 2019/05/22 13:42:41 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	loop;
	char	*s;

	s = (char *)(src);
	loop = -1;
	while (++loop < len && loop < ft_strlen(src) && src[loop])
		dst[loop] = s[loop];
	while (loop < len)
		dst[loop++] = '\0';
	return (dst);
}
