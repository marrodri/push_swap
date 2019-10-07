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

int	sa(t_list **st_a)
{
	int *i;

	i = swap(st_a);
	ft_printf("sa\n");
	return (0);
}

int	ra(t_list **st_a) 
{
	int *i;

	i = rot(st_a);
	ft_printf("ra\n");
	return (0);
}

int	rra(t_list **st_a)
{
	int *i;

	i = rrot(st_a);
	ft_printf("rra\n");
	return (0);
}
