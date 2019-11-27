/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sortedSt_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:12:05 by marrodri          #+#    #+#             */
/*   Updated: 2019/11/08 15:12:07 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//TODO ADD THE FUNCTIONS TO FINALLY PROPERLY SORT, by rotating and pushing
// elements from stack b to rotating stack a, and finally rotating when everything
// is sorted

//TODO CHECKPOINT HERE THIS 

void		setStckBHiValTop(t_app **app, t_list *st_b)
{
	(*app)->stck_b_hi_val = stck_hiVal(st_b);
	(*app)->len_stck_b = ft_list_size(st_b);
	(*app)->stck_b_hi_val_ind = stck_valInd(st_b,(*app)->stck_b_hi_val);
	ft_printf("stB hivalIndex index: %d\n", (*app)->stck_b_hi_val_ind);
	//rb
	(*app)->sort_stb_flag[0] = (*app)->stck_b_hi_val_ind;
	//rrb
	(*app)->sort_stb_flag[1] = ((*app)->len_stck_b - (*app)->stck_b_hi_val_ind);
	if ((*app)->sort_stb_flag[1] == (*app)->len_stck_b)
	{
		(*app)->sort_stb_flag[1] = 0;
	}
	rotInstrCheck(app);
}

void		setSortedInst(t_app **app, t_list *st_a, t_list *st_b)
{
	int stHiLowInd;
	int stAHiLow;

	if(st_b)
	{
		(*app)->stck_b_hi_val = stck_hiVal(st_b);
		// 2.- check how many ra, rra rb, rrb are needed to rotate the element to the top 
		(*app)->len_stck = ft_list_size(st_a);
		(*app)->len_stck_b = ft_list_size(st_b);
		stAHiLow = stcka_midValComp(st_a, (*app)->stck_b_hi_val);
		stHiLowInd = stck_valInd(st_a, stAHiLow);

		ft_printf("stAHiLow is %d\n", stAHiLow);
		ft_printf("stAHiLow index: %d\n", stHiLowInd);
		ft_printf("stack len is %d\n", (*app)->len_stck);
		(*app)->sort_sta_flag[0] = stHiLowInd; //ra
		(*app)->sort_sta_flag[1] = ((*app)->len_stck - stHiLowInd); //rra
		if((*app)->sort_sta_flag[1] == (*app)->len_stck)
		{
			(*app)->sort_sta_flag[1] = 0;
		}
		ft_printf("moving for stack b\n");
		ft_printf("ra:%d\n", (*app)->sort_sta_flag[0]);
		ft_printf("rra:%d\n", (*app)->sort_sta_flag[1]);
		(*app)->sort_sta_flag[3] = 1;
	}
	else
	{
		ft_printf("stack b is NULL\n");
		ft_printf("ra:%d\n", (*app)->sort_sta_flag[0]);
		ft_printf("rra:%d\n", (*app)->sort_sta_flag[1]);
		// ft_printf("rb:%d\n", (*app)->sort_stb_flag[0]);
		// ft_printf("rrb:%d\n", (*app)->sort_stb_flag[1]);
		(*app)->sort_sta_flag[0] = ch_ra_sta(st_a);
		(*app)->sort_sta_flag[1] = ch_rra_sta(st_a);
	}
	rotInstrCheck(app);
	// 3.- lastly add the push flag to stack A
	ft_printf("sorted instructions are:\n");
	ft_printf("ra:%d\n", (*app)->sort_sta_flag[0]);
	ft_printf("rra:%d\n", (*app)->sort_sta_flag[1]);
	ft_printf("rb:%d\n", (*app)->sort_stb_flag[0]);
	ft_printf("rrb:%d\n", (*app)->sort_stb_flag[1]);
}