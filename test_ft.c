
#include "push_swap.h"
#include "stdio.h"

void	print_list(t_list **list)
{
	t_list *tmp;


	tmp = *list;
	printf("######printing session########\n");
	while(tmp)
	{
		printf("num is |%lu|\n", tmp->content_size);
		tmp = tmp->next;
	}
	printf("^^^^^EXIT CHECK^^^^^^^\n");
}

// t_list 	*ft_set_num(int *num)
// {
// 	t_list	*elem;

// 	if ((elem = (t_list *)malloc(sizeof(t_list))) == NULL)
// 		return (NULL);
// 	if (num)
// 	{
// 		elem->content = num;
// 		elem->content_size = 0;
// 	}
// 	else
// 	{
// 		elem->content = NULL;
// 		elem->content_size = 0;
// 	}
// 	elem->next = NULL;
// 	return (elem);
// }

// void	add_elem(t_list **list, int num)
// {
// 	t_list	*elem;
// }

int main()
{
	t_list *st_a; //list
	t_list *st_b;
	t_list *elem_a; //first elem;
	t_list *elem_b; //sec elem;
	t_list *elem_c; //third elem;
	t_list *elem_d;
	t_list *head1;
	t_list *head2;
	int *a;
	int *b;
	int *c;
	int *d;
	a = malloc(sizeof(int));
	b = malloc(sizeof(int));
	c = malloc(sizeof(int));
	d = malloc(sizeof(int));
	*a = 9;
	*b = 543;
	*c = 234234;
	*d = -12;
	printf("here!!!!!!!\n");
	st_a = NULL;
	st_b = NULL;
	//head for reset struct pos
	elem_a = malloc(sizeof(t_list));
	elem_b = malloc(sizeof(t_list));
	elem_c = malloc(sizeof(t_list));
	elem_d = malloc(sizeof(t_list));
	elem_a->content_size = *a;
	// printf("content in elem a |%lu|\n", elem_a->content_size);
	elem_a->next = NULL;
	elem_b->content_size = *b;
	elem_b->next = NULL;
	elem_c->content_size = *c;
	elem_c->next = NULL;
	elem_d->content_size = *d;
	elem_d->next = NULL;
	st_a = elem_a;
	// printf("first node in stack a |%lu|\n", st_a->content_size);
	head1 = st_a;
	st_a->next = elem_b;
	st_a = st_a->next;
	// printf("content in elem b |%lu|\n", elem_b->content_size);
	// printf("second node in stack a |%lu|\n", st_a->content_size);
	st_a->next = elem_c;
	st_a = st_a->next;
	// printf("content in elem c |%lu|\n", elem_c->content_size);
	// printf("third node in stack a |%lu|\n", st_a->content_size);
	st_a->next = NULL;

	// printf("third node in stack a |%lu|\n", st_a->content_size);
	st_a = head1;

	st_b = elem_d;
	head2 = st_b;
	st_b->next = elem_a;
	st_b = st_b->next;
	st_b->next = elem_c;
	st_b = st_b->next;
	st_b = head2;
	// printf("content in head |%lu|\n", head->content_size);
	print_list(&st_a);
	print_list(&st_b);
	swap_s(&st_a, &st_b);
	printf("!!!!!!!!!!!!!!SWAPED STACK A n B!!!!!!!!!!!!\n");
	// print_list(&st_a);
	// print_list(&st_b);

	// sleep(10);
	return 0;
}