/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 09:44:54 by mbotes            #+#    #+#             */
/*   Updated: 2019/06/29 13:03:05 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

int	ft_strncmp(char const *s1, char const *s2, size_t n)
{
	size_t	loop;
	int		diff;

	loop = 0;
	if (n <= 0 || s1 == NULL || s2 == NULL)
		return (0);
	diff = (unsigned char)s1[loop] - (unsigned char)s2[loop];
	while (diff == 0 && loop < n - 1 && s1[loop] && s2[loop])
	{
		loop++;
		diff = (unsigned char)s1[loop] - (unsigned char)s2[loop];
	}
	return (diff);
}
