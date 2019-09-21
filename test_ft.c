
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


int main()
{
	t_list *st_a; //list
	t_list *st_b;
	printf("here!!!!!!!\n");
	st_a = NULL;
	st_b = NULL;
	add_new_elem(&st_a, 63);
	add_new_elem(&st_a, 23);
	add_new_elem(&st_a, 95);
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
	// printf("^^^^^^push stack a to b^^^^^^^\n");
	// push(&st_b, &st_a);
	// print_list(&st_a);
	// print_list(&st_b);

	printf("&&&&&push stack b to a&&&&&\n");
	push(&st_a, &st_b);
	push(&st_a, &st_b);
	print_list(&st_a);
	print_list(&st_b);

	rot(&st_a);
	printf("11111rotated stack a1111111\n");
	print_list(&st_a);

	rot(&st_a);
	print_list(&st_a);
	// sleep(10);
	return 0;
}