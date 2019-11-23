
#include "push_swap.h"

int		ch_next_hi_elem(t_list *stack)
{
	t_list	*tmp;
	int		prev_elem;
	int		hi_elem;
	int		low_elem;

	hi_elem = stck_hiVal(stack);
	low_elem = stck_lowVal(stack);

	if (stack == NULL || stack->next == NULL)
		return (0);
	tmp = stack;
	prev_elem = tmp->elem;
	tmp = tmp->next;
	if (tmp->elem > prev_elem && 
		(tmp->elem != hi_elem || prev_elem != low_elem))
		return (1);
	return (0);
}

// int		ch_first_low_elem(t_list *stack, t_app *app)
// {
// 	t_list	*tmp;
// 	int		low_elem;

// 	if (stack == NULL || stack->next == NULL || app->len_stck <= 2)
// 		return (0);
// 	tmp = stack;
// 	low_elem = tmp->elem;
// 	while (tmp->next)
// 		tmp = tmp->next;
// 	if (tmp->elem > low_elem)
// 		return (1);
// 	return (0);
// }

int				ch_rb_stb(t_list *st_b)
{
	int i;
	int index;
	int prev_val;
	t_list *head;
	// 1-2-3-5-4-6-7
	i = 0;
	head = st_b;
	index = 0;
	while(st_b->next)
		st_b = st_b->next;

	prev_val = st_b->elem;
	st_b = head;
	while(st_b)
	{
		if(prev_val < st_b->elem)
		{
			index = i;
			if(index == 0)
			{
				index = 2;
			}
			break;
		}
		i++;
		prev_val = st_b->elem;
		st_b = st_b->next;
	}
	//TODO check how many instr. needed to rotate the hi/low elem using only ra;
	// for checking the hi_elem with ra goes an additional step if the len of the stack is odd
	return (index - 1);
}

int				ch_rrb_stb(t_list *st_b)
{
	int i;
	int index;
	int prev_val;
	t_list *head;
	// 1-2-3-5-4-6-7
	i = 0;
	head = st_b;
	index = 0;
	while(st_b->next)
		st_b = st_b->next;
	while(st_b)
	{
		if (prev_val > st_b->elem)
		{
			index = i;
		}
		i++;
		prev_val = st_b->elem;
		st_b = st_b->next;
	}
	return (index + 1);
}



// int		ch_last_hi_elem(t_list *stack, t_app *app)
// {
// 	t_list	*tmp;
// 	t_list	*head;
// 	int		high_elem;

// 	if (stack == NULL || stack->next == NULL || app->len_stck <= 2)
// 		return (0);
// 	tmp = stack;
// 	head = stack;
// 	while (tmp->next)
// 		tmp = tmp->next;
// 	high_elem = tmp->elem;
// 	tmp = head;
// 	while (tmp->next)
// 		tmp = tmp->next;
// 	if (tmp->elem < high_elem)
// 		return (1);
// 	return (0);
// }

// int		ch_special_case_b(t_list *stack, t_app *app)
// {
// 	stack = NULL;
// 	app = NULL;
// 	return 0;
// }
