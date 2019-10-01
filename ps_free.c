
#include "push_swap.h"

void		free_words(char **instr)
{
	int i;
	char	*tmp;
	i = 0;
	if(instr == NULL)
		return ;
	while(instr[i])
	{
		// /ft_printf("freeing ins|%s|\n", (*app)->instr[i]);
		free(instr[i]);
		tmp = NULL;
		i++;
	}
	free(instr);
}

void		free_list(t_list **list)
{
	t_list *tmp;

	if(*list == NULL)
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

// void	free_prog(t_app **app, t_list **st_a, t_list **st_b)
// {

// }