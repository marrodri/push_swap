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

void	act_sta(t_app **app, t_list **st_a)
{
	t_ps_ft *sort_a[3];
	int		i;
	int		j;

	i = 0;
	sort_a[0] = ra;
	sort_a[1] = rra;
	sort_a[2] = sa;
	while(!(*app)->sort_sta_flag[i] && i < 3)
	{
		i++;
	}
	if((*app)->sort_sta_flag[i])
	{
		j = sort_a[i](st_a);
		(*app)->sort_sta_flag[i] = 0;
		(*app)->instr_count++;
	}
}

void	act_stb(t_app **app, t_list **st_b)
{
	int			i;
	int			j;
	t_ps_ft	*sort_b[3];
	
	i = 0;
	sort_b[0] = rb;
	sort_b[1] = rrb;
	sort_b[2] = sb;
	while(!(*app)->sort_stb_flag[i] && i < 3)
	{
		i++;
	}
	if((*app)->sort_stb_flag[i])
	{
		j = sort_b[i](st_b);
		(*app)->sort_stb_flag[i] = 0;
		(*app)->instr_count++;
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
	while (i < 3)
	{
		if ((*app)->sort_sta_flag[i] && (*app)->sort_stb_flag[i])
		{
			sort_both[i](st_a, st_b);
			(*app)->sort_sta_flag[i] = 0;
			(*app)->sort_stb_flag[i] = 0;
			(*app)->instr_count++;
		}
		i++;
	}
}

void	st_act_ft(t_app **app, t_list **st_a, t_list **st_b)
{
	act_st_both(app, st_a, st_b);
	act_sta(app, st_a);
	act_stb(app, st_b);

	//add here the push method
	if (!check_stack(*st_a))
	{
		push(st_b, st_a);
		ft_printf("pb\n");
		(*app)->instr_count++;
	}
	else if (!check_stack_r(*st_b))
	{
		push(st_a, st_b);
		ft_printf("pa\n");
		(*app)->instr_count++;
	}

	/*
	** IF BOTH STACKS ARE SORTED PROPERLY, PUSH ALL TO STA
	*/
	if (check_stack(*st_a) && check_stack_r(*st_b))
	{
		push(st_a, st_b);
		(*app)->instr_count++;
		ft_printf("pa\n");
	}
}
