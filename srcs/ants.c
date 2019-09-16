/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 08:55:31 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/16 15:15:03 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem_in.h"

void	ft_init_ants(t_rooms *head, char *ants)
{
	t_rooms		*ptr;
	long long	n;

	ptr = head;
	while (ptr && !ptr->start)
		ptr = ptr->next;
	if (ptr == NULL)
		ft_error_start();
	if (ft_isnumber(ants))
	{
		n = ft_atoi(ants);
		if (n > 0 && n < 2147483647)
			ptr->no_ants = n;
		else
		{
			ft_putendl("Number of ants need to be a valid number");
			exit(0);
		}
	}
	else
		ft_error_s_ants();
}

t_list	**ft_moveant(t_list **arr, int n, t_route *head, t_env *env)
{
	int		loop;
	t_rooms	*room;
	t_list	*ptr;
	t_route	*paths;

	loop = -1;
	paths = head;
	while (arr[++loop] != NULL)
	{
		room = arr[loop]->content;
		if (room->end)
			continue ;
		ptr = arr[loop]->next;
		arr[loop] = ptr;
		room = ptr->content;
		room->no_ants++;
		if (env->c)
			ft_putcolor((loop + 1) % 10);
		ft_print_ant(loop + 1, room->name);
		if (arr[loop + 1] || n != 0)
			ft_putstr(" ");
	}
	env->head = head;
	arr = ft_add_ant_m(arr, &loop, n, env);
	return (arr);
}

t_list	**ft_add_ant_m(t_list **arr, int *loop, int n, t_env *e)
{
	t_route	*paths;
	int		i;
	t_rooms	*room;

	paths = e->head;
	i = 0;
	while (i < n)
	{
		arr[*loop] = paths->route_h->next;
		paths = paths->next;
		room = arr[*loop]->content;
		room->no_ants++;
		if (e->c)
			ft_putcolor((*loop + 1) % 10);
		ft_print_ant((*loop) + 1, room->name);
		room = e->head->route_h->content;
		room->no_ants--;
		if (i != n - 1)
			ft_putstr(" ");
		(*loop)++;
		i++;
	}
	return (arr);
}

void	ft_print_ants(t_route *path, t_env *env)
{
	t_list	**arr;
	t_rooms	*room;
	int		ants;
	int		n;
	int		a;

	room = path->route_h->content;
	ants = room->no_ants;
	a = ants;
	arr = ft_init_arr(a);
	room = path->route_t->content;
	while (a > room->no_ants)
	{
		room = path->route_h->content;
		ants = room->no_ants;
		n = ft_can_ant_m(path, ants);
		ft_moveant(arr, n, path, env);
		ft_putendl("");
		room = path->route_t->content;
	}
	free(arr);
}

int		ft_can_ant_m(t_route *path, int ants)
{
	int		t_ants;
	int		loop;
	int		cur;
	t_route	*ptr;

	loop = 0;
	ptr = path;
	t_ants = 0;
	cur = 0;
	while (t_ants < ants)
	{
		while (ptr && ptr->size == cur && t_ants < ants)
		{
			loop++;
			t_ants++;
			ptr = ptr->next;
		}
		t_ants += loop;
		cur++;
	}
	return (loop);
}
