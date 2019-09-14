/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 09:32:57 by mbotes            #+#    #+#             */
/*   Updated: 2019/05/21 10:01:15 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t len)
{
	size_t			loop;
	unsigned char	*pr;

	loop = -1;
	pr = (unsigned char*)ptr;
	while (++loop < len)
		pr[loop] = 0;
}
