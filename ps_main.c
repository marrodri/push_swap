/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:09:12 by marrodri          #+#    #+#             */
/*   Updated: 2019/09/27 15:09:15 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_app(t_app **app)
{
	*app = malloc(sizeof(t_app));
	(*app)->arr_num = NULL;
	(*app)->instr = NULL;
	(*app)->len_inst = 0;
	(*app)->len_stck = 0;
}

int main(int argc, char **argv)
{
	t_list	*st_a;
	t_list	*st_b;
	t_app	*app;
	//TODO create an algo that sorts the stack

	st_a = NULL;
	st_b = NULL;
	init_app(&app);
	if(set_int_arr(argv, argc, &app))
	{
		set_stack(&st_a, app, app->arr_num);
		while(!check_stacks(st_a, st_b))
		{
			//check_first_elem that is the highest(){} ra 
			//check if the before_last elem is the highest rra
			// 
			// when sorting, sort and print the instr at the same time
				//sort_stacks (st_a, st_b, "any ins in str");
				//print instruct
		}
	}
	return 0;
}
