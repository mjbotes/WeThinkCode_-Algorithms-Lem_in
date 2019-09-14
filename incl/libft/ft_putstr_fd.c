/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 12:02:54 by mbotes            #+#    #+#             */
/*   Updated: 2019/06/29 11:40:24 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	unsigned int	loop;

	loop = 0;
	if (s != NULL)
		while (s[loop] != '\0')
		{
			ft_putchar_fd(s[loop], fd);
			loop++;
		}
}
