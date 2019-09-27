
//add functions based on adding and deleting lists
#include "push_swap.h"

t_list 	*ft_set_node(int num, void *cont, size_t size)
{
	t_list	*new;

	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (num || cont || size)
	{
		new->elem = num;
		new->content = cont;
		new->content_size = size;
	}
	else
	{
		new->elem = 0;
		new->content = NULL;
		new->content_size = 0;
	}
	new->next = NULL;
	return (new);
}

void	add_new_elem(t_list **alist, int num)
{
	t_list	*new_node;

	new_node = ft_set_node(num, NULL, 0);
	if(*alist == NULL)
		*alist = new_node;
	else
		ft_lstaddend(alist, new_node);
}

void	set_stack(t_list **stack, t_app *app, int *num)
{
	int i;

	i = 0;
	while(i < app->len_stck)
	{
		add_new_elem(stack, num[i]);
		i++;
	}
	ft_printf("finish setting stack\n");
	free(app->arr_num);
}