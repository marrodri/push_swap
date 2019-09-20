
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
	t_list *elem_a; //first elem;
	t_list *elem_b; //sec elem;
	t_list *elem_c; //third elem;
	t_list *head;
	int *a;
	int *b;
	int *c;

	a = malloc(sizeof(int));
	b = malloc(sizeof(int));
	c = malloc(sizeof(int));
	*a = 9;
	*b = 543;
	*c = 234234;
	printf("here!!!!!!!\n");
	st_a = NULL;
	//head for reset struct pos
	elem_a = malloc(sizeof(t_list));
	elem_b = malloc(sizeof(t_list));
	elem_c = malloc(sizeof(t_list));
	elem_a->content_size = *a;
	printf("content in elem a |%lu|\n", elem_a->content_size);
	elem_a->next = NULL;
	elem_b->content_size = *b;
	elem_b->next = NULL;
	elem_c->content_size = *c;
	elem_c->next = NULL;
	st_a = elem_a;
	printf("first node in stack a |%lu|\n", st_a->content_size);
	st_a->next = elem_b;
	head = st_a;
	st_a = st_a->next;
	printf("content in elem b |%lu|\n", elem_b->content_size);
	printf("second node in stack a |%lu|\n", st_a->content_size);
	st_a->next = elem_c;
	st_a = st_a->next;
	printf("content in elem c |%lu|\n", elem_c->content_size);
	printf("third node in stack a |%lu|\n", st_a->content_size);
	st_a->next = NULL;
	
	// printf("third node in stack a |%lu|\n", st_a->content_size);
	st_a = head;
	printf("content in head |%lu|\n", head->content_size);
	print_list(&st_a);
	return 0;
}