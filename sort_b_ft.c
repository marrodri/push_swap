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

int		sb(t_list **st_b)
{
	int *i;
	i = swap(st_b);
	ft_printf("sb\n");
	return (*i);
}

int	rb(t_list **st_b)
{
	int *i;
	i = rot(st_b);
	ft_printf("rb\n");
	return (*i);
}

int	rrb(t_list **st_b)
{
	int *i;
	i = rrot(st_b);
	ft_printf("rrb\n");
	return (*i);
}
