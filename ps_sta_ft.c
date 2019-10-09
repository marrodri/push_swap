/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:27:19 by marrodri          #+#    #+#             */
/*   Updated: 2019/09/30 14:27:20 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ch_next_low_elem(t_list *stack, t_app *app)
{
	t_list	*tmp;
	int		prev_elem;

	if (stack == NULL || stack->next == NULL  || app->len_stck <= 1)
		return (0);
	tmp = stack;
	prev_elem = tmp->elem;
	tmp = tmp->next;
	if (tmp->elem < prev_elem)
		return (1);
	return (0);
}

int		ch_first_hi_elem(t_list *stack, t_app *app)
{
	t_list	*tmp;
	int		high_elem;

	if (stack == NULL || stack->next == NULL || app->len_stck <= 2)
		return (0);
	tmp = stack;
	high_elem = tmp->elem;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->elem < high_elem)
		return (1);
	return (0);
}

//double check this one
int		ch_last_low_elem(t_list *stack, t_app *app)
{
	t_list	*tmp;
	t_list	*head;
	int		low_elem;

	if (stack == NULL || stack->next == NULL || app->len_stck <= 2)
		return (0);
	tmp = stack;
	head = stack;
	while (tmp->next)
		tmp = tmp->next;
	low_elem = tmp->elem;
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->elem > low_elem)
		return (1);
	return (0);
}

int		ch_special_case_a(t_list *stack, t_app *app)
{
	int		i;
	t_list	*prev;
	t_list	*ahead;
	if(app->sort_sta_flag[0] || stack == NULL || stack->next == NULL)
		return 0;
	prev = stack;
	stack = stack->next;
	stack = stack->next;
	// if(stack->next == NULL)
	// 	return 0;
	// ft_printf("prev\n");
	// print_stack(&prev);
	// ft_printf("stack ahead\n");
	// print_stack(&stack);
	if(ch_next_low_elem(stack, app) && ch_next_low_elem(prev, app))
		return 1;
	return 0;
}