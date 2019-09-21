/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:30:25 by marrodri          #+#    #+#             */
/*   Updated: 2019/09/19 16:30:27 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*tmp;
	t_list  *backup;

	tmp = *stack;
	*stack = (*stack)->next;
	backup = (*stack)->next;
	(*stack)->next = tmp;
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->next = backup;
	*stack = tmp;
}

void	swap_s(t_list **stack_a, t_list **stack_b)
{
 	swap(stack_a);
	swap(stack_b);
}
