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

void	rot(t_list *stack)
{
	t_list	*first_elem;
	t_list	*tmp;
	t_list	*last_elem;
	// rotates the specific stack
	//the first element of the stack becomes the last element

}

//rotates bot stack a and stack b
void	rot_r(t_list *stack_a, t_list *stack_b)
{
	rot(stack_a);
	rot(stack_b);
}

void	rrot(t_list *stack)
{
	t_list	*first_elem;
	t_list	*tmp;
	t_list	*last_elem;
	//reverse rotation the specific stack
	//the last element of the stack becomes the first element
}

//reverse rotation both stack a and stack b
void	rrot_r(t_list *stack_a, t_list *stack_b)
{
	rrot(stack_a);
	rrot(stack_b);
}
