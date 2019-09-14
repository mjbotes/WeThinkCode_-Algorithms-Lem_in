/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:31:00 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/14 12:47:45 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem_in.h"

void	ft_error_links(char *name)
{
	ft_putstr("Error: in the link speccifiers there is an unknown room ->");
	ft_putendl(name);
	exit(0);
}

void	ft_error_start(void)
{
	ft_putendl("Starting room has not been speccified.");
	exit(0);
}
