/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 07:30:23 by mbotes            #+#    #+#             */
/*   Updated: 2019/05/23 13:36:42 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			size;
	unsigned int	loop;
	char			*str;

	loop = 0;
	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	if (!(str = ft_strnew(size)))
		return (NULL);
	while (s[loop] != '\0')
	{
		str[loop] = f(loop, (char)s[loop]);
		++loop;
	}
	str[loop] = '\0';
	return (str);
}
