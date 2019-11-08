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
	int			i;

	i = 0;


	// revamp

	// STACK IGNORE
	//FOR RA, RRA

	// THEN PB
	// incase for both instructions uses a high number of steps, substract the half
	// difference and add to PB, or if there's nothing else to do also add 1 PB
	
	//for ra, rra check how many instr. need to rotate the hi_val or low_val to it's destination
	//same for stack b
	//incase for both equal go to rra (in stack b should be different)
	sta_ft[0] = ch_first_hi_elem; //ra,
	sta_ft[1] = ch_last_low_elem; //rra
	sta_ft[2] = ch_next_low_elem; //sa, use this after rotating, check the next one is lower than the current
	while (i < 3)
	{
		(*app)->sort_sta_flag[i] = sta_ft[i](st_a, *app);
		i++;
	}
}

int stAIsSorted()
{
	return 0;
}
void	set_sort_flag(t_app **app, t_list *st_a, t_list *st_b)
{
	//first step 
	if(stAIsSorted())
	{
		//add a checker if everything above is 0 for pushing
		//OR IF BOTH STACKS/ STACK A OR STACK B ARE SORTED
		// TRY TO push the val from STACK B TO STACK A 
		// TODO algo to set instr. for sorted stacks;
	}
	else
	{
		//if not then, goes the sort both stacks algo
		sta_flag(app, st_a);
		stb_flag(app, st_b);
	}

	// TODO CHECK IF BOTH SAME INSTR ARE ACTIVE,
	// if if both instructions are active, but different
	// value, cut to the shortest value between the 2
	// in case of passing what stated above, 
	// set the others instr. to 0 except the both active

	return ;
}
