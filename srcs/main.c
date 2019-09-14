/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:33:48 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/14 16:12:21 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem_in.h"

int	main(int ac, char **av)
{
	int fd;
	t_rooms	*head;
	t_rooms	*ptr;
	t_route	*paths;

	fd = 0;
	head = NULL;
	head = ft_init(fd, &head);
	ptr = head;
	while (!ptr->start)
		ptr = ptr->next;
	ptr = ptr->links->content;
	paths = ft_route_finder(head);
	if (paths)
		ft_print_routes(paths);
}
