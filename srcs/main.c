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

t_env	*ft_option(int ac, char **av, int *fd)
{
	int		loop;
	int		inloop;
	t_env	*env;

	env = ft_init_env();
	loop = 0;
	while (++loop < ac)
		if (av[loop][0] == '-')
		{
			ft_putendl("L");
			inloop = 0;
			while (av[loop][++inloop] != '\0')
				if (av[loop][inloop] == 'f' && loop + 1 < ac)
					*fd = open(av[loop + 1], O_RDONLY);
				else if (av[loop][inloop] == 'r')
					env->r = 1;
				else if (av[loop][inloop] == 'd')
					env->d = 1;
				else if (av[loop][inloop] == 'p')
					env->p = 1;
		}
	return (env);
}

int		main(int ac, char **av)
{
	int 	fd;
	char 	*ants;
	t_rooms	*head;
	t_rooms	*ptr;
	t_route	*paths;

	fd = 0;
	head = NULL;
	ft_option(ac, av, &fd);
	if (get_next_line(fd, &ants) <= 0 || !ft_isnumber(ants))
		ft_error_s_ants();
	head = ft_init(fd, &head);
	ft_init_ants(head, ants);
	if (!head || !head->next || !head->next->next)
		ft_error_room();
	ft_putendl("");
	paths = ft_route_finder(head);
	ft_route_thinner(paths);
	if (paths)
		ft_print_routes(paths);
	ft_delete_rooms(&head);
	ft_delete_routes(&paths);
	//sleep(60);
}
