/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 09:45:52 by mbotes            #+#    #+#             */
/*   Updated: 2019/05/21 09:11:05 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	loop;

	loop = 0;
	if (!(new = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (loop <= size)
		new[loop++] = '\0';
	return (new);
}
