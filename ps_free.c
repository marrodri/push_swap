
#include "push_swap.h"

void		free_words(t_app **app)
{
	int i;

	i = 0;
	while((*app)->instr[i])
	{
		free((*app)->instr[i]);
		(*app)->instr[i] = NULL;
		i++;
	}
	free((*app)->instr);
	(*app)->instr = NULL;
}

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