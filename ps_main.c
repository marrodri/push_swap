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
	(*app)->stIsSplt = 0;

	(*app)->len_stck = 0;
	(*app)->stck_a_hi_val = 0;
	(*app)->stck_a_hi_val_ind = 0;
	(*app)->stck_a_mid_val = 0;
	(*app)->stck_a_mid_val_ind = 0;
	(*app)->stck_a_low_val = 0;
	(*app)->stck_a_low_val_ind = 0;

	(*app)->len_stck_b = 0;
	(*app)->stck_b_hi_val = 0;
	(*app)->stck_b_hi_val_ind = 0;
	(*app)->stck_b_mid_val = 0;
	(*app)->stck_b_mid_val_ind = 0;
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

	st_a = NULL;
	st_b = NULL;
	init_ps(&app);
	if (check_arg(argv, argc, &app))
	{
		set_stack(&st_a, app);
		setChunkLen(&app, st_a);
		// CHECKPOINT
		setChunkRange(&app, st_a);
		// while (0)
		while (!check_stacks(st_a, st_b) && !app->stIsSplt)
		{
			if(app->deb_flag)
				ft_printf("-----sort-------\n");
			app->len_stck_b = ft_list_size(st_b);
			chunk_instr(&app, st_a);
			//change to split_chunk
			if (app->chunkSet)
			{
				setChunkRange(&app, st_a);
				mergeStack(&app, &st_a, &st_b);
			}
			else
			{
				chunk_instr(&app, st_a);
			}

			// change logic
			//  instead of going through to put the lowest num
			// sort by finding the closest num to the top, that 
			//  is inside the area of the chunk
			set_sort_flag(&app, st_a, st_b);
			st_act_ft(&app, &st_a, &st_b);

			if(app->deb_flag)
				print_stacks(st_a, st_b);
		}
	}
	if(app->deb_flag)
		ft_printf("intructions used |%d|\n", app->instr_count);
	return (0);
}
