/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_set_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 20:39:43 by marrodri          #+#    #+#             */
/*   Updated: 2019/10/01 20:39:45 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// NOTE use this page to finish chunk_instr as a guide
// If everything works fine without this page, remove it.

void	stb_flag(t_app **app, t_list *st_b)
{

	//set the stack_b checker, if the stack b is now sorted, don't do anything
	if(st_b)
	{
		(*app)->sort_stb_flag[0] = ch_rb_stb(st_b); //rb
		(*app)->sort_stb_flag[1] = ch_rrb_stb(st_b); //rrb
		(*app)->sort_stb_flag[2] = ch_next_hi_elem(st_b, *app); //sb
	}
}

// REVAMP THIS
void	sta_flag(t_app **app, t_list *st_a)
{
	// search for any misplaced number
	// if a misplace number is founded, put to the second position from the top,
	// then swap the values
	// same for stack b

	// incase for both equal go to rra
	// sa, use this after rotating, check the next one is lower than the current
	(*app)->sort_sta_flag[0] = ch_ra_sta(st_a);
	(*app)->sort_sta_flag[1] = ch_rra_sta(st_a);
	(*app)->sort_sta_flag[2] = ch_next_low_elem(st_a);
}

void	saInstrCheck(t_app **app)
{
	if ((*app)->sort_sta_flag[2])
	{
		(*app)->sort_sta_flag[0] = 0;
		(*app)->sort_sta_flag[1] = 0;
	}
	if ((*app)->sort_stb_flag[2])
	{
		(*app)->sort_stb_flag[0] = 0;
		(*app)->sort_stb_flag[1] = 0;
	}
}

//remodify this one
void	rotInstrCheck(t_app **app)
{
	if((*app)->sort_sta_flag[0] >= (*app)->sort_sta_flag[1] && 
	(*app)->sort_sta_flag[1] > 0)
	{
		(*app)->sort_sta_flag[0] = 0;
	}
	else if ((*app)->sort_sta_flag[0] < (*app)->sort_sta_flag[1] &&
		(*app)->sort_sta_flag[0] > 0)
	{
		(*app)->sort_sta_flag[1] = 0;
	}
	if((*app)->sort_stb_flag[0] >= (*app)->sort_stb_flag[1] && 
		(*app)->sort_stb_flag[1] > 0)
	{
		(*app)->sort_stb_flag[0] = 0;
	}
	else if((*app)->sort_stb_flag[0] < (*app)->sort_stb_flag[1] &&
		(*app)->sort_stb_flag[0] > 0)
	{
		(*app)->sort_stb_flag[1] = 0;
	}
}

void	bothInstrCheck(t_app **app)
{
	int i;

	i = 0;
	while(i < 4)
	{
		if((*app)->sort_sta_flag[i] > (*app)->sort_stb_flag[i]
		 && (*app)->sort_stb_flag[i] > 0)
		{
			(*app)->sort_sta_flag[i] = (*app)->sort_stb_flag[i];
		}
		else if((*app)->sort_sta_flag[i] < (*app)->sort_stb_flag[i]
		 && (*app)->sort_sta_flag[i] > 0)
		{
			(*app)->sort_stb_flag[i] = (*app)->sort_sta_flag[i];
		}
		i++;
	}
}

void	set_sort_flag(t_app **app, t_list *st_a, t_list *st_b)
{
	//if stack a has only 10 chunks, then sort the stack a properly
	if (stARotSort(*app, st_a))
	{
		setSortedInst(app, st_a, st_b);
		rotInstrCheck(app);
	}
	else
	{
		sta_flag(app, st_a);
		stb_flag(app, st_b);
		if((*app)->deb_flag)
		{
			ft_printf("======PRE INSTRUCTIONS==========\n");
			print_inst(*app);
		}
		saInstrCheck(app);
		rotInstrCheck(app);
		// bothInstrCheck(app);
		
	}


	if((*app)->deb_flag)
	{
		ft_printf("++++++++FINAL INSTRUCTIONS+++++\n");
		print_inst(*app);
	}
	return ;
}
