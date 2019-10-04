/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_act_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:45:17 by marrodri          #+#    #+#             */
/*   Updated: 2019/10/04 15:45:20 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	act_stb()
{
	t_stack_ft *sort_b[3];

	sort_b[0] = rb;
	sort_b[1] = rrb;
	sort_b[2] = sb;
}

void	act_sta()
{
	t_stack_ft *sort_a[3];
}

void	st_act_ft(t_app **app, t_list **st_a, t_list **st_b)
{
	if ((*app)->sort_sta_flag[0] && (*app)->sort_stb_flag[0])
	{
		ft_printf("rr\n");
	}
	if ((*app)->sort_sta_flag[1] && (*app)->sort_stb_flag[1])
	{
		ft_printf("rrr\n");
	}
	if ((*app)->sort_sta_flag[2] && (*app)->sort_stb_flag[2])
	{
		ft_printf("ss\n");
	}


	/*
	** IF BOTH STACKS ARE SORTED PROPERLY, PUSH ALL TO STA
	*/
	if (check_stack(*st_a) && check_stack_r(*st_b))
	{
		while(check_stack_r(*st_b))
		{
			push(st_a, st_b);
			(*app)->instr_count++;
			ft_printf("pa\n");
		}
	}
}
