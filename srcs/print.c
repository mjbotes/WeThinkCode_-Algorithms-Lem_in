/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:49:02 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/16 15:07:22 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem_in.h"

void	ft_print_routes(t_route *head)
{
	t_route	*ptr;
	t_list	*l;
	t_rooms	*r;

	ptr = head;
	if (ptr)
	{
		l = ptr->route_h;
		while (l)
		{
			r = (t_rooms *)l->content;
			if (l->next && r->name)
			{
				ft_putstr(r->name);
				ft_putstr("  ->  ");
			}
			else
				ft_putendl(r->name);
			l = l->next;
		}
	}
	else
		return ;
	ft_print_routes(head->next);
}

void	ft_print_r(t_rooms *room)
{
	if (room->end)
		ft_putendl("END");
	else if (room->start)
		ft_putendl("START");
	else
		ft_putendl("LINK");
}

void	ft_print_links(t_rooms *head)
{
	t_rooms *room;
	t_list	*lst;
	t_rooms	*ptr;

	room = head;
	while (room)
	{
		ft_putstr("Room name: ");
		ft_putendl(room->name);
		ft_putendl("------------------");
		ft_print_r(room);
		ft_putendl("------------------");
		ft_putendl("This room links to:");
		lst = room->links;
		while (lst)
		{
			ptr = lst->content;
			ft_putendl(ptr->name);
			lst = lst->next;
		}
		room = room->next;
		ft_putendl("");
	}
}

void	ft_print_ant(int ant, char *name)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(name);
}

void	ft_print_options(t_env *env, t_route *paths, t_rooms *head)
{
	if (env->l || env->d)
	{
		ft_putendl("██╗     ██╗███╗   ██╗██╗  ██╗███████╗");
		ft_putendl("██║     ██║████╗  ██║██║ ██╔╝██╔════╝");
		ft_putendl("██║     ██║██╔██╗ ██║█████╔╝ ███████╗");
		ft_putendl("██║     ██║██║╚██╗██║██╔═██╗ ╚════██║");
		ft_putendl("███████╗██║██║ ╚████║██║  ██╗███████║");
		ft_putendl("╚══════╝╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝╚══════╝");
		ft_putendl("=====================================\n");
		ft_print_links(head);
	}
	if (env->r || env->d)
	{
		ft_putendl("██████╗  ██████╗ ██╗   ██╗████████╗███████╗███████╗");
		ft_putendl("██╔══██╗██╔═══██╗██║   ██║╚══██╔══╝██╔════╝██╔════╝");
		ft_putendl("██████╔╝██║   ██║██║   ██║   ██║   █████╗  ███████╗");
		ft_putendl("██╔══██╗██║   ██║██║   ██║   ██║   ██╔══╝  ╚════██║");
		ft_putendl("██║  ██║╚██████╔╝╚██████╔╝   ██║   ███████╗███████║");
		ft_putendl("╚═╝  ╚═╝ ╚═════╝  ╚═════╝    ╚═╝   ╚══════╝╚══════╝");
		ft_putendl("===================================================\n");
		ft_print_routes(paths);
		ft_putendl("");
	}
}
