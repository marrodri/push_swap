
#include "push_swap.h"

void		free_list(t_list **list)
{
	t_list *tmp;

	while (*list)
	{
		tmp = (*list)->next;
		if ((*list)->content)
		{
			(*list)->content_size = 0;
			(*list)->elem = 0;
			(*list)->content = NULL;
		}
		free(*list);
		(*list) = NULL;
		*list = tmp;
	}
}