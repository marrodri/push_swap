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

void	act_stb(t_app **app, t_list **st_a)
{
	t_ps_ft *sort_a[3];
	int		i;

	i = 0;
	sort_a[0] = ra;
	sort_a[1] = rra;
	sort_a[2] = sa;
	while()
	{
		i++;
	}
}

void	act_stb(t_app **app, t_list **st_b)
{
	int			i;
	t_ps_ft	*sort_b[3];

	i = 0;
	sort_b[0] = rb;
	sort_b[1] = rrb;
	sort_b[2] = sb;
	while(!(*app)->sort_stb_flag[i])
	{
		i++;
	}
}

void	act_st_both(t_app **app, t_list **st_a, t_list **st_b)
{
	int i;
	t_ps_both_ft *sort_both[3];

	i = 0;
	sort_both[0] = rr;
	sort_both[1] = rrr;
	sort_both[2] = ss;

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
}

void	st_act_ft(t_app **app, t_list **st_a, t_list **st_b)
{
	act_st_both(app, st_a, st_b);


	//add here the push method
	if (!check_stack(st_a))
	{
		push(&st_b, &st_a);
		ft_printf("pb\n");
		(*app)->instr_count++;
	}
	else if (!check_stack_r(st_b))
	{
		push(&st_a, &st_b);
		ft_printf("pa\n");
		(*app)->instr_count++;
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
