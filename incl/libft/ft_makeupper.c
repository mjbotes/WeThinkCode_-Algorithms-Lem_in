/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makeupper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 09:45:51 by mbotes            #+#    #+#             */
/*   Updated: 2019/08/09 10:57:39 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_makeupper(char *str)
{
	int	loop;

	loop = -1;
	while (str[++loop] != '\0')
		str[loop] = ft_toupper(str[loop]);
	return (str);
}
