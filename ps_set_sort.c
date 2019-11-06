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
	t_stIns		*stack_inst;
	int			i;

	i = 0;
	stack_inst = malloc(sizeof(t_stIns));
	stb_ft[0] = ch_first_low_elem; //rb
	stb_ft[1] = ch_last_hi_elem; //rrb
	stb_ft[2] = ch_next_hi_elem; //sb
	while (i < 3 && ft_arriszero((*app)->sort_stb_flag, 3))
	{
		(*app)->sort_stb_flag[i] = stb_ft[i](st_b, *app);
		i++;
	}
	//add special cases for pa
	// if (ft_arriszero((*app)->sort_stb_flag, 3) &&
	// 	ft_arriszero((*app)->sort_sta_flag, 4))
	// 	(*app)->sort_stb_flag[3] = 1;

	
	free(stack_inst);
}

// REVAMP THIS
void	sta_flag(t_app **app, t_list *st_a)
{
	// ft_printf("======FLAG SESSION=======\n");
	t_stack_fl	*sta_ft[3];
	t_stIns		*stack_inst;
	int			i;

	i = 0;
	stack_inst = malloc(sizeof(t_stIns));

	//find the highest value position

	// revamp
	// TODO: change the functions to void

	// FOR SA FIRST
	// check if the top is higher than the next, however if the top value is the HIGHEST OF THE

	// STACK IGNORE
	//FOR RA, RRA
	// first step, check between ra and rra the least number of steps,
	//when rotating it shouldn't go past the half of the stack, if rotating
	//goes a higher number steps than the half len of the stack,
	// check the difference then push the difference and come here again

	// THEN PB
	// incase for both instructions uses a high number of steps, substract the half
	// difference and add to PB, or if there's nothing else to do also add 1 PB

	sta_ft[0] = ch_first_hi_elem; //ra,
	sta_ft[1] = ch_last_low_elem; //rra
	sta_ft[2] = ch_next_low_elem; //sa, use this after rotating, check the next one is lower than the current
	while (i < 3 && ft_arriszero((*app)->sort_sta_flag, 3))
	{
		(*app)->sort_sta_flag[i] = sta_ft[i](st_a, *app);
		i++;
	}





	// if (ch_double_pb_a(st_a, *app))
	// {
	// 	// ft_printf("we got double double pb\n");
	// 	(*app)->sort_sta_flag[0] = 0;
	// 	(*app)->sort_sta_flag[1] = 0;
	// 	(*app)->sort_sta_flag[2] = 0;
	// 	(*app)->sort_sta_flag[3] = 2;
	// }


	// else if (ft_arriszero((*app)->sort_sta_flag, 3))
	// {
	// 		// ft_printf("none inputed\n");
	// 	(*app)->sort_sta_flag[3] = 1;
	// }
	// add special cases for pb
	// if (ft_arriszero((*app)->sort_sta_flag, 3) 
	// 	&& ft_arriszero((*app)->sort_stb_flag, 4) && check_stack(st_a))
	// 	(*app)->sort_sta_flag[3] = 1;
	free(stack_inst);
}

void	set_sort_flag(t_app **app, t_list *st_a, t_list *st_b)
{
	sta_flag(app, st_a);
	stb_flag(app, st_b);
	return ;
}
