
#include "push_swap.h"
#include "stdio.h"

void	print_list(t_list **list)
{
	t_list *tmp;


	tmp = *list;
	printf("######printing session########\n");
	while(tmp)
	{
		printf("num is |%d|\n", tmp->elem);
		tmp = tmp->next;
	}
	printf("^^^^^EXIT CHECK^^^^^^^\n");
}

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

int main()
{
	t_list *st_a; //list
	t_list *st_b;
	printf("here!!!!!!!\n");
	st_a = NULL;
	st_b = NULL;
	add_new_elem(&st_a, 23);
	add_new_elem(&st_a, 32);
	add_new_elem(&st_a, 24);
	// add_new_elem(&st_a, 65);
	//stack_b
	add_new_elem(&st_b, 14);
	add_new_elem(&st_b, 42);
	add_new_elem(&st_b, 64);
	// add_new_elem(&st_b, -435);

	print_list(&st_a);
	print_list(&st_b);
	// swap(&st_a);
	// swap_s(&st_a, &st_b);
	// printf("!!!!!!!!!!!!!!SWAPED STACK A n B!!!!!!!!!!!!\n");
	printf("^^^^^^push stack a to b^^^^^^^\n");
	push(&st_b, &st_a);
	print_list(&st_a);
	print_list(&st_b);

	printf("&&&&&push stack b to a&&&&&\n");
	push(&st_a, &st_b);
	print_list(&st_a);
	print_list(&st_b);
	// sleep(10);
	return 0;
}