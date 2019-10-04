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

void	sort_stb(t_app **app, t_list *st_b)
{
	t_stack_ft *stb_ft[3];
	stb_ft[0] = ch_next_hi_elem;
	stb_ft[1] = ch_first_low_elem;
	stb_ft[2] = ch_last_hi_elem;
	if (ch_next_hi_elem(st_b))
	{
		(*app)->sort_stb_flag[0] = 1;
		swap(&st_b);
		ft_printf("sb\n");
	}
	if (ch_first_low_elem(st_b))
	{
		rot(&st_b);
		ft_printf("rb\n");
		(*app)->instr_count++;
	}
	if (ch_last_hi_elem(st_b))
	{
		rrot(&st_b);
		ft_printf("rrb\n");
		(*app)->instr_count++;
	}
}

void	sort_sta(t_app **app, t_list *st_a)
{
	t_stack_ft *sta_ft[3];

	sta_ft[0] = ch_next_low_elem; //duplicate the funct for a ch_next_low_elem;
	sta_ft[1] = ch_first_hi_elem;
	sta_ft[2] = ch_last_low_elem;
	if (ch_next_low_elem(st_a))
	{
		(*app)->sort_sta_flag[0] = 1;
		swap(&st_a);
		ft_printf("sa\n");
		(*app)->instr_count++;
	}
	if (ch_first_hi_elem(st_a))
	{
		(*app)->sort_sta_flag[1] = 1;
		rot(&st_a);
		ft_printf("ra\n");
		(*app)->instr_count++;
	}
	if (ch_last_low_elem(st_a))
	{
		(*app)->sort_sta_flag[2] = 1;
		rrot(&st_a);
		ft_printf("rra\n");
		(*app)->instr_count++;
	}
}

void	set_sort_ft(t_app **app, t_list *st_a, t_list *st_b)
{
	// rra, rrb
	// if (ch_last_low_elem(st_a))
	// {
	// 	rrot(&st_a);
	// 	ft_printf("rra\n");
	// 	(*app)->instr_count++;
	// }
	if (ch_last_hi_elem(st_b))
	{
		rrot(&st_b);
		ft_printf("rrb\n");
		(*app)->instr_count++;
	}

	//rb, ra
	//set a special algo for ra, rb,
	else if (ch_first_low_elem(st_b))
	{
		rot(&st_b);
		ft_printf("rb\n");
		(*app)->instr_count++;
	}
	
	// if (ch_first_hi_elem(st_a))
	// {
	// 	(*app)->sort_ft_flag[1] = 1;
	// 	rot(&st_a);
	// 	ft_printf("ra\n");
	// }
	// rra, rrb


	//for sa, sb, if both are 1 active, ss
	// if (!ch_next_hi_elem(st_a))
	// {
	// 	(*app)->sort_ft_flag[0] = 1;
	// 	// swap(&st_a);
	// 	// ft_printf("sa\n");
	// }
	if (ch_next_hi_elem(st_b))
	{
		(*app)->sort_ft_flag[4] = 1;
		swap(&st_b);
		ft_printf("sb\n");
	}

	//if all are 0, activate pa or pb,
	return ;
}
