/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 09:13:31 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/14 15:47:02 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"

typedef struct			s_rooms
{
	char				*name;
	t_list				*links;
	int					start;
	int					end;
	struct s_rooms		*next;
}						t_rooms;

void					ft_addroom(t_rooms **head,char *name, t_list *links);
int						ft_room_checker(t_rooms *head, char *name);
t_rooms					*ft_new_room(char *name, t_list *links);
void					ft_delete_rooms(t_rooms **head);
void					ft_set_es(t_rooms *head, char *name, char *c);

t_rooms					*ft_find_room(t_rooms **head, char *name);
t_rooms					**ft_add_link(t_rooms **head, char **arr);

typedef struct			s_route
{
	t_list				*route_h;
	t_list				*route_t;
	int					size;
	struct s_route		*next;
	struct s_route		*prev;
}						t_route;

void					ft_route_pushback(t_route **head, t_route *new_r);
t_route					*ft_make_route_dup(t_route *src);
t_route					*ft_new_route(t_list *list);
void					ft_delete_route(t_route **ptr);

int						ft_check_routes(t_route *head, t_rooms *room);
t_route					*ft_route_finder(t_rooms *rooms);
void					ft_route_stepper(t_route **head);
void					ft_add_route_step(t_route **head,t_route *cur,
							t_rooms *room);

t_rooms					**ft_init_links(t_rooms **head,int fd, char *s);
t_rooms					*ft_init(int fd, t_rooms **head);

void					ft_error_links(char *name);
void					ft_error_start(void);

void					ft_print_routes(t_route *head);

void					ft_del_list(void *c, size_t s);

#endif
