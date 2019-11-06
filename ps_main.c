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

void	print_stack(t_list **list)
{
	t_list *tmp;

	tmp = *list;
	if (tmp == NULL)
	{
		ft_printf("list is NULL\n");
		return ;
	}
	while (tmp)
	{
		ft_printf("[%d]->", tmp->elem);
		tmp = tmp->next;
		if (!tmp)
			ft_printf("NULL\n");
	}
}

void	init_ps(t_app **app)
{
	int i;

	i = 0;
	*app = malloc(sizeof(t_app));
	(*app)->arr_num = NULL;
	(*app)->instr = NULL;
	(*app)->len_inst = 0;
	(*app)->stIsMerged = 0;

	(*app)->len_stck = 0;
	(*app)->stck_a_hi_val = 0;
	(*app)->stck_a_hi_val_ind = 0;
	(*app)->stck_a_low_val = 0;
	(*app)->stck_a_low_val_ind = 0;

	(*app)->len_stck_b = 0;
	(*app)->stck_b_hi_val = 0;
	(*app)->stck_b_hi_val_ind = 0;
	(*app)->stck_b_low_val = 0;
	(*app)->stck_b_low_val_ind = 0;

	while (i < 4)
	{
		(*app)->sort_sta_flag[i] = 0;
		(*app)->sort_stb_flag[i] = 0;
		i++;
	}
	(*app)->instr_count = 0;
}

int main(int argc, char **argv)
{
	t_list		*st_a;
	t_list		*st_b;
	t_app		*app;
	//TODO create an algo that sorts the stack

	st_a = NULL;
	st_b = NULL;
	init_ps(&app);
	if (check_arg(argv, argc, &app))
	{
		set_stack(&st_a, app);
		while (!check_stacks(st_a, st_b))
		{
			// ft_printf("-----sort-------\n");
			app->len_stck = ft_list_size(st_a);
			app->len_stck_b = ft_list_size(st_b);

			if(!app->stIsMerged)
			{
				//TODO MERGE THE STACK
			}


			//TODO create a function that sets 1 to which instructions to use 
			set_sort_flag(&app, st_a, st_b);

			// ft_printf("#1.- passing set sort_flag !!!\n");
			st_act_ft(&app, &st_a, &st_b);
			// ft_printf("printing stack a\n");
			// print_stack(&st_a);
			// ft_printf("printing stack b\n");
			// print_stack(&st_b);
			// ft_printf("========end==========\n");
		}
	}
	// print_stack(&st_a);
	// ft_printf("intructions used |%d|\n", app->instr_count);
	return (0);
}

// sun 2:03
// mon 4:25
// -------  
// 6:28
// tues 3:08
// ---------
// 9:36
// wed 1:47
// --------
// 
// thurs 
// -------  
// 
// fri 
// --------  
// 
// sat 
// ------
// 