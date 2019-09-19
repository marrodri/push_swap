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
	if(stack == NULL)
		return (0);
	while(stack)
	{
		stack = stack->next;
	}
	// return 1 if stack has elements and sorted
	// return 0 if its empty
}

int		check_stacks(t_list *stack_a, t_list *stack_b)
{
	//TODO
	//as safety add if stack_b is NULL;
		//check stack_b if its empty == 0
	// return 1 if 
		//check stack_a if everything sorted == 1
	//if not return 0
}
