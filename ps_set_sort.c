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

void	stb_flag(t_app **app, t_list *st_b)
{
	int			i;

	i = 0;

	// search for any misplaced number
	//if a misplace number is founded, put to the second position from the top,
	//then swap the values

	// stb_ft[0] = ch_first_low_elem; //rb
	// stb_ft[1] = ch_last_hi_elem; //rrb
	(*app)->sort_stb_flag[0] = ch_rb_stb(st_b);
	(*app)->sort_stb_flag[1] = ch_rrb_stb(st_b);
	(*app)->sort_stb_flag[2] = ch_next_hi_elem(st_b, *app); //sb
	// while (i < 3 && ft_arriszero((*app)->sort_stb_flag, 3))
	// {
	// 	(*app)->sort_stb_flag[i] = stb_ft[i](st_b, *app);
	// 	i++;
	// }

}

// REVAMP THIS
void	sta_flag(t_app **app, t_list *st_a)
{
	// search for any misplaced number
	//if a misplace number is founded, put to the second position from the top,
	//then swap the values
	//same for stack b

	//incase for both equal go to rra
	// sta_ft[0] = ch_first_hi_elem; //ra,
	// sta_ft[1] = ch_last_low_elem; //rra
	// sta_ft[2] = ch_next_low_elem; 
	//sa, use this after rotating, check the next one is lower than the current
	(*app)->sort_sta_flag[0] = ch_ra_sta(st_a);
	(*app)->sort_sta_flag[1] = ch_rra_sta(st_a);
	(*app)->sort_sta_flag[2]  = ch_next_low_elem(st_a);
}

//still buggy, segfault probably here!
int stARotSort(t_app *app, t_list *st_a)
{
	t_list *head;
	int prev_val;
	int low_val;

	low_val = stck_lowVal(st_a);
	head = st_a;
	while (st_a->elem != app->stck_a_hi_val)
	{
		st_a = st_a->next;
	}
	prev_val = st_a->elem;
	st_a = st_a->next;
	if(!st_a)
	{
		st_a = head;
	}
	if(st_a->elem != low_val)
	{
		return 0;
	}
	while(1)
	{
		if (!st_a)
			st_a = head;
		if (st_a->elem == app->stck_a_hi_val)
			break;
		if (prev_val > st_a->elem && prev_val != app->stck_a_hi_val 
			&& (st_a->elem != low_val))
			return (0);
		prev_val = st_a->elem;
		st_a = st_a->next;
	}
	return (1);
}

void	saInstrCheck(t_app **app)
{
	if((*app)->sort_sta_flag[2])
	{
		(*app)->sort_sta_flag[0] = 0;
		(*app)->sort_sta_flag[1] = 0;
	}
	if((*app)->sort_stb_flag[2])
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

	ft_printf("updating rot or rrot\n");
	ft_printf("ra:%d\n", (*app)->sort_sta_flag[0]);
	ft_printf("rra:%d\n", (*app)->sort_sta_flag[1]);
	ft_printf("rb:%d\n", (*app)->sort_stb_flag[0]);
	ft_printf("rrb:%d\n", (*app)->sort_stb_flag[1]);
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

	// ft_printf("equaling doubles\n");
	// ft_printf("ra:%d\n", (*app)->sort_sta_flag[0]);
	// ft_printf("rra:%d\n", (*app)->sort_sta_flag[1]);
	// ft_printf("sa:%d\n", (*app)->sort_sta_flag[2]);
	// ft_printf("rb:%d\n", (*app)->sort_stb_flag[0]);
	// ft_printf("rrb:%d\n", (*app)->sort_stb_flag[1]);
	// ft_printf("sb:%d\n", (*app)->sort_stb_flag[2]);
}

void	set_sort_flag(t_app **app, t_list *st_a, t_list *st_b)
{
	//TOFIX IMPORTANT - stARotSort still buggy
	if (stARotSort(*app, st_a))
	{
		ft_printf("+++stack A is sorted, special sort start+++\n");
		setSortedInst(app, st_a, st_b);
	}
	else
	{
		ft_printf("segfault here!\n");
		// todo 2 checkpoint - FIX THE ST_FLAGS
		sta_flag(app, st_a);
		stb_flag(app, st_b);
	}

	ft_printf("ra:%d\n", (*app)->sort_sta_flag[0]);
	ft_printf("rra:%d\n", (*app)->sort_sta_flag[1]);
	ft_printf("sa:%d\n", (*app)->sort_sta_flag[2]);
	ft_printf("rb:%d\n", (*app)->sort_stb_flag[0]);
	ft_printf("rrb:%d\n", (*app)->sort_stb_flag[1]);
	ft_printf("sb:%d\n", (*app)->sort_stb_flag[2]);

	// AN INSTRUCTION CHECKER, to limit as lowest instructions as possible
	saInstrCheck(app);
	rotInstrCheck(app);
	// CHECKS IF BOTH SAME INSTR ARE ACTIVE,
	// if if both instructions are active, but different
	// value, cut to the shortest value between the 2
	bothInstrCheck(app);
	return ;
}
