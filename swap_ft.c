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

int	*swap(t_list **stack)
{

	t_list	*tmp;
	t_list  *backup;

	ft_printf("entering swap a\n");
	tmp = *stack;
	*stack = (*stack)->next;
	backup = (*stack)->next;
	(*stack)->next = tmp;
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->next = backup;
	*stack = tmp;
	ft_printf("finish!!!\n");
	return 0;
}

int	*swap_s(t_list **stack_a, t_list **stack_b)
{
 	swap(stack_a);
	swap(stack_b);
	return 0;
}
