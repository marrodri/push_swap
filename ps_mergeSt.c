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

void	mergeStack(t_app **app, t_list **st_a, t_list **st_b)
{
	int midIndex;
	int ra_inst;
	int rra_inst;

	(*app)->stck_a_hi_val = stck_hiVal(*st_a);
	(*app)->stck_a_hi_val_ind = stck_valInd(*st_a, (*app)->stck_a_hi_val);

	midIndex = ((*app)->len_stck /2);

	// ft_printf("midIndex: %d\n", midIndex);
	// ft_printf("hival: %d\n", (*app)->stck_a_hi_val);
	// ft_printf("hival index: %d\n", (*app)->stck_a_hi_val_ind);
	
	if ((*app)->stck_a_hi_val_ind < midIndex)
	{	
		// if the hi value index is lower than the half of the index
		// rotate the hi val to the last place, wether by ra or rra
		// the push the half of the stack to stack b
		ra_inst = (*app)->stck_a_hi_val_ind + 1;
		rra_inst = midIndex - (*app)->stck_a_hi_val_ind;
		if (ra_inst >= rra_inst)
		{
			while(rra_inst)
			{
				rrot(st_a);
				ft_printf("rra\n");
				rra_inst--;
			}
		}
		else if(ra_inst < rra_inst)
		{
			while(ra_inst)
			{
				rot(st_a);
				ft_printf("ra\n");
				ra_inst--;
			}
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
