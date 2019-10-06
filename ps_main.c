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
	(*app)->len_stck = 0;
	(*app)->len_stck_b = 0;
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
			app->len_stck = ft_list_size(st_a);
			app->len_stck_b = ft_list_size(st_b);
			//TODO create a function that sets 1 to which instructions to use 
			// set_sort_ft(&app, st_a, st_b);

			//TODO move all instructions to another function that sorts based 
			//from the 1s in the sort_ft_flag, and run a dispatch table 

			//check_first_elem that is the highest(){} ra 
			//check if the before_last elem is the highest rra 
			if (ch_last_low_elem(st_a))
			{
				rrot(&st_a);
				ft_printf("rra\n");
				app->instr_count++;
			}
			else if (ch_first_low_elem(st_b))
			{
				rot(&st_b);
				ft_printf("rb\n");
				app->instr_count++;
			}
			else if (ch_last_hi_elem(st_b))
			{
				rrot(&st_b);
				ft_printf("rrb\n");
				app->instr_count++;
			}
			else if (ch_first_hi_elem(st_a))
			{
				rot(&st_a);
				ft_printf("ra\n");
				app->instr_count++;
			}
			//rra and rrb when to use
			else if (!ch_next_hi_elem(st_a))
			{
				swap(&st_a);
				ft_printf("sa\n");
				app->instr_count++;
			}
			else if (ch_next_hi_elem(st_b))
			{
				// (*app)->sort_ft_flag[4] = 1;
				swap(&st_b);
				ft_printf("sb\n");
			}
			if (!check_stack(st_a))
			{
				push(&st_b, &st_a);
				ft_printf("pb\n");
				app->instr_count++;
			}
			else if (!check_stack_r(st_b))
			{
				push(&st_a, &st_b);
				ft_printf("pa\n");
				app->instr_count++;
			}
			// ft_printf("printing stack a\n");
			// print_stack(&st_a);
			// ft_printf("printing stack b\n");
			// print_stack(&st_b);
			if (check_stack(st_a) && check_stack_r(st_b))
			{
				while(check_stack_r(st_b))
				{
					push(&st_a, &st_b);
					app->instr_count++;
					ft_printf("pa\n");
				}
			}
			// check if next elem is lower than the prev_elem;
			// when sorting, sort and print the instr at the same time
				//sort_stacks (st_a, st_b, "any ins in str");
				//print instruct
		}
	}
	ft_printf("intructions used |%d|\n", app->instr_count);
	// ft_printf("stack is sorted\n");
	print_stack(&st_a);
	return (0);
}

//mon 8:44
//tues 6:07
//_-------
// 14:51
// 6:17 wed
// ---------
// 21:08
// 5:41 thurs
//  ------
// 26:49
// 3:24 fri
// -------
// 30:13 
//  3:15 sat
// ---------
// 33:28