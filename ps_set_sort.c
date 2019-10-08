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
	t_stack_fl	*stb_ft[3];
	int			i;

	i = 0;
	stb_ft[0] = ch_first_low_elem; //rb
	stb_ft[1] = ch_last_hi_elem; //rrb
	stb_ft[2] = ch_next_hi_elem; //sb
	while (i < 3 && ft_arriszero((*app)->sort_stb_flag, 3))
	{
		(*app)->sort_stb_flag[i] = stb_ft[i](st_b, *app);
		i++;
	}
	//add special cases for pa
	if (ft_arriszero((*app)->sort_stb_flag, 3) &&
		ft_arriszero((*app)->sort_sta_flag, 4))
		(*app)->sort_stb_flag[3] = 1;
}

void	sta_flag(t_app **app, t_list *st_a)
{
	t_stack_fl	*sta_ft[3];
	int			i;

	i = 0;
	sta_ft[0] = ch_first_hi_elem; //ra
	sta_ft[1] = ch_last_low_elem; //rra
	sta_ft[2] = ch_next_low_elem; //sa
	while (i < 3 && ft_arriszero((*app)->sort_sta_flag, 3))
	{
		(*app)->sort_sta_flag[i] = sta_ft[i](st_a, *app);
		i++;
	}
	//add special cases for pb
	if (ft_arriszero((*app)->sort_sta_flag, 3) 
		&& ft_arriszero((*app)->sort_stb_flag, 4))
		(*app)->sort_sta_flag[3] = 1;
}

void	set_sort_flag(t_app **app, t_list *st_a, t_list *st_b)
{
	sta_flag(app, st_a);
	stb_flag(app, st_b);
	return ;
}
