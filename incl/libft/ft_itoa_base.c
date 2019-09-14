/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 09:37:46 by mbotes            #+#    #+#             */
/*   Updated: 2019/08/09 11:01:31 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(uintmax_t n, int base)
{
	static char	rep[] = "0123456789abcdef";
	static char	*buf;
	uintmax_t	num;
	int			loop;
	uintmax_t	ret;

	num = n;
	loop = 0;
	while (num != 0)
	{
		num /= base;
		loop++;
	}
	if (loop == 0)
		loop = 1;
	buf = ft_strnew(loop);
	ret = n;
	while (loop > 0)
	{
		buf[--loop] = rep[ret % base];
		ret /= base;
	}
	return (buf);
}
