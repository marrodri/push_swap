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

//this one seems useful, yet.
int		ch_next_low_elem(t_list *stack)
{
	t_list	*tmp;
	int		prev_elem;

	if (stack == NULL || stack->next == NULL)
		return (0);
	tmp = stack;
	prev_elem = tmp->elem;
	tmp = tmp->next;
	if (tmp->elem < prev_elem)
		return (1);
	return (0);
}

//
// int		ch_first_hi_elem(t_list *stack, t_app *app)
// {
// 	t_list	*tmp;
// 	int		high_elem;

// 	if (stack == NULL || stack->next == NULL || app->len_stck <= 2)
// 		return (0);
// 	tmp = stack;
// 	high_elem = tmp->elem;
// 	while (tmp->next)
// 		tmp = tmp->next;
// 	if (tmp->elem < high_elem)
// 		return (1);
// 	return (0);
// }

//double check this one
// int		ch_last_low_elem(t_list *stack, t_app *app)
// {
// 	t_list	*tmp;
// 	t_list	*head;
// 	int		low_elem;

// 	if (stack == NULL || stack->next == NULL || app->len_stck <= 2)
// 		return (0);
// 	tmp = stack;
// 	head = stack;
// 	while (tmp->next)
// 		tmp = tmp->next;
// 	low_elem = tmp->elem;
// 	tmp = head;
// 	while (tmp->next)
// 		tmp = tmp->next;
// 	if (tmp->elem > low_elem)
// 		return (1);
// 	return (0);
// }



int		ch_ra_sta(t_list *st_a)
{
	int i;
	int index;
	int prev_val;
	t_list *head;
	// 1-2-3-5-4-6-7
	i = 0;
	head = st_a;
	index = 0;
	while(st_a->next)
		st_a = st_a->next;

	prev_val = st_a->elem;
	st_a = head;
	while(st_a)
	{
		if(prev_val > st_a->elem)
		{
			index = i;
			if(index == 0)
			{
				index = 2;
			}
			break;
		}
		i++;
		prev_val = st_a->elem;
		st_a = st_a->next;
	}
	//TODO check how many instr. needed to rotate the hi/low elem using only ra;
	// for checking the hi_elem with ra goes an additional step if the len of the stack is odd
	return (index - 1);
}

//it still rotates when the head is the lowest and the last stack is the highest 

int rra_exception(t_list *st_a)
{
	int low_val;
	int hi_val;

	hi_val = stck_hiVal(st_a);
	low_val = stck_lowVal(st_a);
	if(st_a->elem != low_val)
	{
		return 0;
	}
	while(st_a->next)
	{
		st_a = st_a->next;
	}
	if(st_a->elem == hi_val)
	{
		return 1;
	}
	return 0;
}
int		ch_rra_sta(t_list *st_a)
{
	//TODO check how many instr. needed to rotate using only rra;
	// for checking the hi_elem with ra goes an additional step
	int i;
	int index;
	int prev_val;
	t_list *head;
	// 1-2-3-5-4-6-7
	i = 0;
	head = st_a;
	index = 0;
	while(st_a->next)
		st_a = st_a->next;
	while(st_a)
	{
		if(prev_val > st_a->elem)
		{
			index = i;
		}
		i++;
		prev_val = st_a->elem;
		st_a = st_a->next;
	}
	st_a = head;
	if(rra_exception(st_a) && index == 0)
	{
		return 0;
	}
	return (index + 1);
}