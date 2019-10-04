/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 16:23:56 by marrodri          #+#    #+#             */
/*   Updated: 2019/10/04 16:24:00 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list **st_b)
{
	swap(&st_b);
	ft_printf("sb\n");
}

void	rb(t_list **st_b)
{
	rot(&st_b);
	ft_printf("rb\n");
}

void	rrb(t_list **st_b)
{
	rrot(&st_b);
	ft_printf("rrb\n");
}
