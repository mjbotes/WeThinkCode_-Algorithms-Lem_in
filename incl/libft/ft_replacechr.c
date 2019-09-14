/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replacechr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 16:03:46 by mbotes            #+#    #+#             */
/*   Updated: 2019/06/17 14:44:16 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_replacechr(char **str, char f, char r)
{
	char	*ptr;

	if ((ptr = ft_strchr(*str, f)) == NULL)
		return (NULL);
	*ptr = r;
	return (ptr);
}
