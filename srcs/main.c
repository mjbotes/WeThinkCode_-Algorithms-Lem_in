/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:33:48 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/16 15:25:32 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem_in.h"

void	ft_help(void)
{
	ft_putendl("██╗  ██╗███████╗██╗     ██████╗");
	ft_putendl("██║  ██║██╔════╝██║     ██╔══██╗");
	ft_putendl("███████║█████╗  ██║     ██████╔╝");
	ft_putendl("██╔══██║██╔══╝  ██║     ██╔═══╝");
	ft_putendl("██║  ██║███████╗███████╗██║");
	ft_putendl("╚═╝  ╚═╝╚══════╝╚══════╝╚═╝");
	ft_putendl("===============================\n");
	ft_putendl("Options:");
	ft_putendl("\t-l : Prints out all the links of each room");
	ft_putendl("\t-r : Prints out all the most effecient group of routes");
	ft_putendl("\t-d : Debugger");
	ft_putendl("\t-c : enables COLOR");
	ft_putendl("\t-f : next argument is the ant farm map");
	exit(0);
}

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
			inloop = 0;
			while (av[loop][++inloop] != '\0')
				if (av[loop][inloop] == 'f' && loop + 1 < ac)
					*fd = open(av[loop + 1], O_RDONLY);
				else if (av[loop][inloop] == 'r')
					env->r = 1;
				else if (av[loop][inloop] == 'd')
					env->d = 1;
				else if (av[loop][inloop] == 'l')
					env->l = 1;
				else if (av[loop][inloop] == 'c')
					env->c = 1;
				else if (av[loop][inloop] == 'h')
					ft_help();
		}
	return (env);
}

int		main(int ac, char **av)
{
	int		fd;
	char	*ants;
	t_rooms	*head;
	t_route	*paths;
	t_env	*env;

	fd = 0;
	head = NULL;
	env = ft_option(ac, av, &fd);
	if (!(get_next_line(fd, &ants) > 0 && ft_isnumber(ants)))
		ft_error_s_ants();
	ft_putendl(ants);
	head = ft_init(fd, &head);
	ft_check_rooms(head);
	ft_init_ants(head, ants);
	ft_putendl("");
	paths = ft_route_finder(head);
	ft_check_if_ends(paths);
	if (!paths)
		ft_putendl("NO LINK PATHS TO END");
	ft_route_thinner(paths);
	ft_print_options(env, paths, head);
	ft_print_ants(paths, env);
	ft_delete_rooms(&head);
	ft_delete_routes(&paths);
}
