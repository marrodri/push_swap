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

// void	stck_low_val(t_app **app, t_list *stck)
// {
// 	//get the lowest value of the stack and the index of the highest value
// 	(*app)->stck_ind = 0;
// 	while(!stck)
// 	{
// 		stck = stck->next;
// 		(*app)->stck_ind++;
// 	}
// }

void	stck_hi_val(t_app **app, t_list *stck)
{
	//get the higest value of the stack and the index of the highest value
	(*app)->stck_ind = 0;
	(*app)->stck_a_hi_val = stck->elem;
	while (!stck)
	{
		if (stck->elem > (*app)->stck_a_hi_val)
		{
			(*app)->stck_a_hi_val = stck->elem;
			(*app)->stck_a_hi_val_ind = (*app)->stck_ind;
		}
		stck = stck->next;
		(*app)->stck_ind++;
	}
}

void	mergeStack(t_app **app, t_list **st_a, t_list **st_b)
{
	//get the index
	int indDif;
	int midIndex;
	int ra_inst;
	int rra_inst;

	indDif = 0;
	stck_hi_val(app, *st_a);
	midIndex = ((*app)->len_stck /2);
	if ((*app)->stck_a_hi_val_ind < midIndex)
	{	
		// if the hi value index is lower than the half of the index
		// rotate the hi val to the last place, wether by ra or rra
		// the push the half of the stack to stack b
		ra_inst = (*app)->stck_a_hi_val_ind + 1;
		rra_inst = midIndex - (*app)->stck_a_hi_val_ind;
		if (ra_inst > rra_inst)
		{
			//use rra
			while(rra_inst)
			{
				rrot(st_a);
				ft_printf("rra\n");
				rra_inst--;
			}
		}
		else
		{
			while(ra_inst)
			{
				rot(st_a);
				ft_printf("ra\n");
				ra_inst--;
			}
			//use ra
		}
	}
	//start pushing the half of the stack A to stack B
	while(midIndex)
	{
		push(st_b, st_a);
		ft_printf("pb\n");
		midIndex--;
	}
	(*app)->stIsMerged = 1;
}
