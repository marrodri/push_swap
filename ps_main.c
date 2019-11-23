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


void	init_ps(t_app **app)
{
	int i;

	i = 0;
	*app = malloc(sizeof(t_app));
	(*app)->arr_num = NULL;
	(*app)->instr = NULL;
	(*app)->len_inst = 0;
	(*app)->chunk_ind = 1;
	(*app)->len_stck = 0;
	(*app)->stck_a_hi_val = 0;
	(*app)->stck_a_hi_val_ind = 0;
	(*app)->stck_a_mid_val = 0; //delete this one at the end
	(*app)->stck_a_mid_val_ind = 0; //delete this one at the end
	(*app)->stck_a_low_val = 0;
	(*app)->stck_a_low_val_ind = 0;

	(*app)->len_stck_b = 0;
	(*app)->stck_b_hi_val = 0;
	(*app)->stck_b_hi_val_ind = 0; 
	(*app)->stck_b_mid_val = 0; //delete this one at the end
	(*app)->stck_b_mid_val_ind = 0; //delete this one at the end
	(*app)->stck_b_low_val = 0;
	(*app)->stck_b_low_val_ind = 0;

	while (i < 4)
	{
		(*app)->sort_sta_flag[i] = 0;
		(*app)->sort_stb_flag[i] = 0;
		i++;
	}
	(*app)->deb_flag = 0;
	(*app)->instr_count = 0;
}

int main(int argc, char **argv)
{
	t_list		*st_a;
	t_list		*st_b;
	t_app		*app;

	int i;

	i = 0;

	st_a = NULL;
	st_b = NULL;
	init_ps(&app);
	if (check_arg(argv, argc, &app))
	{
		set_stack(&st_a, app);
		setChunkLen(&app, st_a);
		setChunkRange(&app, st_a);
		// chunk_instr(&app, st_a, st_b);
		// while (0)
		if(app->deb_flag)
		{
			ft_printf("stack set:\n");
			print_stacks(st_a, st_b);
		}
		while (!check_stacks(st_a, st_b))
		{
			if (app->deb_flag)
				ft_printf("-----sort-------\n");
			app->len_stck = ft_list_size(st_a);
			app->len_stck_b = ft_list_size(st_b);
			if (app->chunkSet)
			{
				setChunkRange(&app, st_a);
				// mergeStack(&app, &st_a, &st_b);
			}
			// CHECKPOINT HERE
			chunk_instr(&app, st_a, st_b);
			//CHECKPOINT TO SEE IF THE INSTR_SET WORKS, WIP
			// break;
			st_act_ft(&app, &st_a, &st_b);
			// TODO add a chunk_checker that sets the chunkset to true
			checkChunk(&app, st_b);
			// if the first chunk range is setted on stack a
			if(app->deb_flag)
				print_stacks(st_a, st_b);
			i++;
		}
	}
	if(app->deb_flag)
		ft_printf("intructions used |%d|\n", app->instr_count);
	return (0);
}

// sun 0:00 
// mon 8:45 
// ------- 
// 8:45 
// tues 3:52 
// --------- 
// 12:37 
// wed 1:55 
// -------- 
// 14:15 
// thurs 5:43 
// ------- 
// 19:58
// fri 6:41 
// -------- 
// 26:39 
// sat 
// -------- 
// 

// thurs and fri, 8 hours each
