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

void	set_sort_ft(t_sort_fl **sort_fl, t_list *st_a, t_list *st_b)
{
	if (ch_first_hi_elem(st_a))
	{
		(*sort_fl)->ra = 1;
		// rot(&st_a);
		// ft_printf("ra\n");
	}
	if (!ch_next_hi_elem(st_a))
	{
		(*sort_fl)->sa = 1;
		// swap(&st_a);
		// ft_printf("sa\n");
	}
}
