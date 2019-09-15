

#include "../incl/lem_in.h"

t_env	*ft_init_env(void)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	new->d = 0;
	new->p = 0;
	new->r = 0;
	return (new);
}
