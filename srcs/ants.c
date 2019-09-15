

#include "../incl/lem_in.h"

void	ft_init_ants(t_rooms *head, char *ants)
{
	t_rooms *ptr;

	ptr = head;
	while (ptr && !ptr->start)
		ptr = ptr->next;
	if (ptr == NULL)
		ft_error_start();
	if (ft_isnumber(ants))
		ptr->no_ants = ft_atoi(ants);
	else
		ft_error_s_ants();
}

void	ft_print_ants(t_route *path)
{
	t_route	*ptr;
	int		ant;

	ptr = path;
}

void	ft_can_ant_m(t_route *path)
{

}
