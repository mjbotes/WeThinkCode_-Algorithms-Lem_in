/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 09:46:55 by mbotes            #+#    #+#             */
/*   Updated: 2019/05/21 09:00:20 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int loop;

	loop = ft_strlen(str) + 1;
	while (--loop >= 0)
		if (str[loop] == (char)c)
			return ((char*)&str[loop]);
	return (NULL);
}
