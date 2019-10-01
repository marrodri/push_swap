
#include "push_swap.h"

void		free_words(char **instr)
{
	int i;

	i = 0;
	if (*instr == NULL)
	{
		free(instr);
		return ;
	}
	while (instr[i])
	{
		free(instr[i]);
		instr[i] = NULL;
		i++;
	}
	free(instr);
}

void		free_list(t_list **list)
{
	t_list *tmp;

	if (*list == NULL)
		return ;
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

void	free_prog(t_app **app, t_list **st_a, t_list **st_b)
{
	if ((*app)->arr_num)
		free((*app)->arr_num);
	if ((*app)->instr)
		free_words((*app)->instr);
	if ((*app)->free_av)
		free_words((*app)->av);
	free(*app);
	free_list(st_a);
	free_list(st_b);
}