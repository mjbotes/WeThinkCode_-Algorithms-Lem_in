/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 09:46:22 by mbotes            #+#    #+#             */
/*   Updated: 2019/05/28 14:34:23 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	loop;
	size_t	inloop;

	loop = 0;
	if (ft_strlen(str2) == 0)
		return ((char*)str1);
	while (str1[loop] != '\0' && loop < len)
	{
		inloop = 0;
		while (str2[inloop] == str1[loop + inloop] && loop + inloop < len)
			if (str2[++inloop] == '\0')
				return ((char*)&str1[loop]);
		loop++;
	}
	return (NULL);
}
