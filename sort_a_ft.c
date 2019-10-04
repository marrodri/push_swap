/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 16:24:08 by marrodri          #+#    #+#             */
/*   Updated: 2019/10/04 16:24:10 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

// for sa if false, sb if true
void	sa(t_list **st_a)
{
	swap(&st_a);
	ft_printf("sa\n");
}

void	ra(t_list **st_a)
{
	rot(&st_a);
	ft_printf("ra\n");
}

void	rra(t_list **st_a)
{
	rrot(&st_a);
	ft_printf("rra\n");
}
