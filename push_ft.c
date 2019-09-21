/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:31:14 by marrodri          #+#    #+#             */
/*   Updated: 2019/09/19 16:31:15 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack_dst, t_list **stack_src)
{
	//push the very first element from stack_src to stack_dst
	if(stack_src == NULL)
		return ;
	t_list *tmp;
	tmp = *stack_src;
	(*stack_src) = (*stack_src)->next;
	tmp->next = *stack_dst;
	*stack_dst = tmp;
	// return (1);
}

// void	push_b(t_list *stack_a, t_list *stack_b)
// {
// 	t_list *tmp;
// 	//push the very first element from stack a to stack b
// }
