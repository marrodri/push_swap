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
	t_stack_ft	*stb_ft[3];
	int			i;

	i = 0;
	stb_ft[0] = ch_next_hi_elem;
	stb_ft[1] = ch_first_low_elem;
	stb_ft[2] = ch_last_hi_elem;
	while (i < 3)
	{
		(*app)->sort_stb_flag[i] = stb_ft[i](st_b);
		i++;
	}
	if (ft_arriszero((*app)->sort_stb_flag, 3))
		(*app)->sort_stb_flag[3] = 1;
}

void	sort_sta(t_app **app, t_list *st_a)
{
	t_stack_ft	*sta_ft[3];
	int			i;

	i = 0;
	sta_ft[0] = ch_next_low_elem;
	sta_ft[1] = ch_first_hi_elem;
	sta_ft[2] = ch_last_low_elem;
	while (i < 3)
	{
		(*app)->sort_sta_flag[i] = sta_ft[i](st_a);
		i++;
	}
	if (ft_arriszero((*app)->sort_sta_flag, 3))
		(*app)->sort_sta_flag[3] = 1;
}

void	set_sort_ft(t_app **app, t_list *st_a, t_list *st_b)
{

	// if (ft_arriszero((*app)->sort_sta_flag, 3))
	// 	(*app)->sort_sta_flag[3] = 1;
	// if (ft_arriszero((*app)->sort_stb_flag, 3))
	// 	(*app)->sort_stb_flag[3] = 1;
	return ;
}
