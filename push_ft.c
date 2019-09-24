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
	t_list *tmp;

	if (*stack_src == NULL)
		return ;
	if (*stack_dst == NULL)
	{
		*stack_dst = *stack_src;
		*stack_src = (*stack_src)->next;
		(*stack_dst)->next = NULL;
		return ;
	}
	tmp = *stack_src;
	(*stack_src) = (*stack_src)->next;
	tmp->next = *stack_dst;
	*stack_dst = tmp;
}
