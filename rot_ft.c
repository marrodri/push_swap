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
#include "stdio.h"

void	rot(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	tail = *stack;
	// tail->next = NULL;
	*stack = (*stack)->next;
	head = *stack;
	printf("stack elem is |%d|\n", (*stack)->elem);
		printf("here\n");
	while((*stack)->next)
	{
		*stack = (*stack)->next;
	}
	tail->next = NULL;
	(*stack)->next = tail;

	*stack = head;
	// rotates the specific stack
	//the first element of the stack becomes the last element

}

//rotates bot stack a and stack b
void	rot_r(t_list **stack_a, t_list **stack_b)
{
	rot(stack_a);
	rot(stack_b);
}

void	rrot(t_list **stack)
{
	t_list	*head;
	t_list	*tail;
	//reverse rotation the specific stack
	//the last element of the stack becomes the first element
}

//reverse rotation both stack a and stack b
void	rrot_r(t_list **stack_a, t_list **stack_b)
{
	rrot(stack_a);
	rrot(stack_b);
}
