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

	init_app(&app);
	//TODO create an algo that sorts the stack
	// ft made to use
	//set_int_arr(argv, argc, &app)
	//set_stack(st_a, app, app->arr_num);
	// when sorting, sort and print the instr at the same time
	//while check_stacks(st_a, st_b) still 0, keep sorting
		//sort_stacks (st_a, st_b, "any ins in str");
		//print instruct
}
