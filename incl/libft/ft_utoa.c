/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 10:48:12 by mbotes            #+#    #+#             */
/*   Updated: 2019/06/19 06:59:34 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(uintmax_t num)
{
	unsigned int	loop;

	loop = 0;
	if (num < 0)
	{
		num = num * -1;
		loop++;
	}
	while (num >= 10)
	{
		num = num / 10;
		loop++;
	}
	loop++;
	return (loop);
}

char		*ft_utoa(uintmax_t n)
{
	unsigned int	loop;
	char			*new;
	uintmax_t		num;
	uintmax_t		rem;

	loop = ft_intlen(n);
	if (!(new = ft_strnew(loop)))
		return (NULL);
	num = n;
	if (n < 0)
		num = num * -1;
	new[loop--] = '\0';
	while (num >= 10)
	{
		rem = num % 10;
		num = num / 10;
		new[loop--] = rem + '0';
	}
	new[loop--] = num + '0';
	if (n < 0)
		new[loop] = '-';
	return (new);
}
