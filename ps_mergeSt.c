/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_mergeSt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:54:20 by marrodri          #+#    #+#             */
/*   Updated: 2019/11/06 14:54:22 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void stck_hi_val(t_app **app, t_list *stck)
{
	//get the higest value of the stack and the index of the highest value
	(*app)->stck_ind = 0;
	while(!stck)
	{
		stck = stck->next;
		(*app)->stck_ind++;
	}
}

void stck_low_val(t_app **app, t_list *stck)
{
	//get the lowest value of the stack and the index of the highest value
	(*app)->stck_ind = 0;
	while(!stck)
	{
		stck = stck->next;
		(*app)->stck_ind++;
	}
	
}

void mergeStack(t_app **app, t_list **st_a, t_list **st_b)
{
	//get the index

	/* if the highest value is below the middle index, move it to the
	the end or higher position than the index middle*/

	/* if not then start pushing until theres only half of the stacks */


	(*app)->stIsMerged = 1;
	/*try to use ss, rr, rra, as much as posible*/
}