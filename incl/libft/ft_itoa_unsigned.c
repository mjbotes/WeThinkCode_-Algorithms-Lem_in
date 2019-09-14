/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 09:05:44 by mbotes            #+#    #+#             */
/*   Updated: 2019/08/09 10:53:39 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long unsigned int num)
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

char		*ft_itoa_unsigned(unsigned int n)
{
	unsigned int		loop;
	char				*new;
	long unsigned int	num;
	int					rem;

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
