/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_ft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:30:38 by marrodri          #+#    #+#             */
/*   Updated: 2019/09/19 16:30:40 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*rot(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	tail = *stack;
	*stack = (*stack)->next;
	head = *stack;
	while ((*stack)->next)
		*stack = (*stack)->next;
	tail->next = NULL;
	(*stack)->next = tail;
	*stack = head;
	return (0);
}

int	*rot_r(t_list **stack_a, t_list **stack_b)
{
	rot(stack_a);
	rot(stack_b);
	return (0);
}

int	*rrot(t_list **stack)
{
	t_list	*cur_hd;
	t_list	*new_hd;
	t_list	*tail;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	cur_hd = *stack;
	while ((*stack)->next)
	{
		tail = *stack;
		(*stack) = (*stack)->next;
		if ((*stack)->next == NULL)
			new_hd = *stack;
	}
	(*stack)->next = cur_hd;
	(*stack) = tail;
	(*stack)->next = NULL;
	(*stack) = new_hd;
	return (0);
}

int	*rrot_r(t_list **stack_a, t_list **stack_b)
{
	rrot(stack_a);
	rrot(stack_b);
	return (0);
}
