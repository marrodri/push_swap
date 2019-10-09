
#include "push_swap.h"

int		ch_next_hi_elem(t_list *stack, t_app *app)
{
	t_list	*tmp;
	int		prev_elem;

	if (stack == NULL || stack->next == NULL)
		return (0);
	tmp = stack;
	prev_elem = tmp->elem;
	tmp = tmp->next;
	if (tmp->elem > prev_elem)
		return (1);
	return (0);
}

int		ch_first_low_elem(t_list *stack, t_app *app)
{
	t_list	*tmp;
	int		low_elem;

	if (stack == NULL || stack->next == NULL || app->len_stck <= 2)
		return (0);
	tmp = stack;
	low_elem = tmp->elem;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->elem > low_elem)
		return (1);
	return (0);
}

int		ch_last_hi_elem(t_list *stack, t_app *app)
{
	t_list	*tmp;
	t_list	*head;
	int		high_elem;

	if (stack == NULL || stack->next == NULL || app->len_stck <= 2)
		return (0);
	tmp = stack;
	head = stack;
	while (tmp->next)
		tmp = tmp->next;
	high_elem = tmp->elem;
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->elem < high_elem)
		return (1);
	return (0);
}

// int		ch_special_case_b(t_list *stack, t_app *app)
// {
// 	stack = NULL;
// 	app = NULL;
// 	return 0;
// }
