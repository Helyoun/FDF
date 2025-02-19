#include "libft.h"

void	ft_free_list(t_list **list, void **ptr)
{
	void	*tmp;

	while (*list != NULL)
	{
		tmp = (*list)->next;
		free ((*list)->array);
		free (*list);
		*list = tmp;
	}
	free(*ptr);
	*ptr = NULL;
	exit (0);
}
