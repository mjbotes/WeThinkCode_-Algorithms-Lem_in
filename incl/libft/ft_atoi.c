/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 09:26:15 by mbotes            #+#    #+#             */
/*   Updated: 2019/08/13 14:24:58 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *str)
{
	int			sign;
	long long	res;
	int			loop;

	sign = 1;
	res = 0;
	loop = 0;
	while (ft_iswhitespace(str[loop]) == 1)
		loop++;
	if (str[loop] == '-' || str[loop] == '+')
		if (str[loop++] == '-')
			sign = -1;
	while (ft_isdigit(str[loop]) == 1 && str[loop] != '\0')
	{
		res = res * 10;
		res += str[loop++] - '0';
	}
	return (res * sign);
}
