/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makeunsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 09:44:58 by mbotes            #+#    #+#             */
/*   Updated: 2019/08/09 10:55:16 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

unsigned int	ft_makeunsigned(int num)
{
	int				*ptr;
	unsigned int	*ret;

	ptr = &num;
	ret = (unsigned int*)ptr;
	return (*ret);
}
