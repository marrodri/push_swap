/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:31:29 by marrodri          #+#    #+#             */
/*   Updated: 2019/09/19 16:31:31 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list **list)
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

	st_a = NULL;
	st_b = NULL;
	init_app(&app);
	int i;

	i = 0;
	if (argc >= 2)
	{
		if (set_int_arr(argv, argc, &app) && set_instr(0, &app))
		{
			set_stack(&st_a, app, app->arr_num);
			ft_printf("^^^here^^^\n");
			while (app->instr[i])
			{
				sort_stacks(&st_a, &st_b, app->instr[i]);
				i++;
				ft_printf("int i |%d|\n", i);
			}
			ft_printf("showing stack A!!!!!!!\n");
			print_list(&st_a);
			ft_printf("showing STACK B????????\n");
			print_list(&st_b);
			if (check_stacks(st_a, st_b))
				ft_printf("OK\n");
			else
				ft_printf("KO\n");
			
		}
		else
		{
			ft_printf("showing stack A!!!!!!!\n");
			print_list(&st_a);
			ft_printf("showing STACK B????????\n");
			print_list(&st_b);
			ft_printf("Error\n");
		}
	}
	else
		ft_printf("usage: stdin instruction | ./checker <argument integer [min = 2 args]>\n");
	free_words(app->instr);
	free(app);
	free_list(&st_a);
	free_list(&st_b);
	sleep(5);
	return (0);
}

//IMPORTANT sa, ra, rra, sa input show error