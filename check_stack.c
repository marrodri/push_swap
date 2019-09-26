/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:31:47 by marrodri          #+#    #+#             */
/*   Updated: 2019/09/19 16:31:48 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_stack(t_list *stack)
{
	int a;
	int b;
	
	if(stack == NULL)
		return (0);
	a = stack->elem; //prev
	stack = stack->next;
	while(stack)
	{
		// return 0 if stack is not sorted
		b = stack->elem; //next
		if(a > b)
			return 0;
		a = stack->elem;
		stack = stack->next;
	}
	// return 1 if stack has elements and sorted
	return (1);
}

int		check_stacks(t_list *stack_a, t_list *stack_b)
{
	//TODO
	//as safety add if stack_b is NULL;
	if(check_stack(stack_a) && !check_stack(stack_b))
	{
		//check stack_b if its empty == 0
		return (1);
	}
	else
		return (0);
}
