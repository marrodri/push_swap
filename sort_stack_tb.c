/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:30:10 by marrodri          #+#    #+#             */
/*   Updated: 2019/09/19 16:30:11 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		search_instr(char *instr)
{
	int			i;
	const char	*ps_inst[PS_INS_SZ] = PS_INST;

	i = 0;
	while (i < PS_INS_SZ)
	{
		if (!ft_strcmp(instr, ps_inst[i]))
			break ;
		i++;
	}
	return (i);
}

void	init_tb(t_sort **sort_arr, t_sort_both **sort_both_arr)
{
	sort_arr[0] = swap;
	sort_arr[1] = rot;
	sort_arr[2] = rrot;
	sort_both_arr[0] = swap_s;
	sort_both_arr[1] = rot_r;
	sort_both_arr[2] = rrot_r;
}

void	sort_stacks(t_list **stack_a, t_list **stack_b, char *instr)
{
	t_sort		*sort_arr[PS_INS_SZ];
	t_sort_both	*sort_both_arr[PS_INSB_SZ];
	int			i;
	int			*j;

	i = search_instr(instr);
	init_tb(sort_arr, sort_both_arr);
	if (i >= 0 && i <= 2)
		j = (sort_arr[i](stack_a));
	else if (i >= 3 && i <= 5)
	{
		i = i - 3;
		j = (sort_arr[i](stack_b));
	}
	else if (i >= 6 && i <= 8)
	{
		i = i - 6;
		j = (sort_both_arr[i](stack_a, stack_b));
	}
	else if (i == 9)
		push(stack_a, stack_b);
	else if (i == 10)
		push(stack_b, stack_a);
	return ;
}
