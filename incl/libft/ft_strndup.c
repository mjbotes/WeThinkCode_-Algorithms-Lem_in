/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:29:37 by mbotes            #+#    #+#             */
/*   Updated: 2019/05/29 08:28:05 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t len)
{
	char	*new;

	if (!(new = ft_strnew(len)))
		return (NULL);
	ft_strncpy(new, str, len + 1);
	new[len] = '\0';
	return (new);
}
