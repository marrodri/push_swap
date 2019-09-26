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
	while(tmp)
	{
		ft_printf("[%d]->", tmp->elem);
		tmp = tmp->next;
		if(!tmp)
			ft_printf("NULL\n");
	}
}

void	init_app(t_app **app)
{

}


int main(int argc, char **argv)
{
	t_list	*st_a;
	t_list	*st_b;
	t_app	*app;

	st_a = NULL;
	st_b = NULL;
	app = malloc(sizeof(t_app));
	int i;

	i = 0;
	if (argc >= 2)
	{
		if (set_int_arr(argv, argc, &app) && set_instr(0, &app))
		{
			set_stack(&st_a, app, app->arr_num);
			// print_list(&st_a);
			while(app->instr[i])
			{
				sort_stacks(st_a, st_b, app->instr[i]);
				i++;
				ft_printf("int i |%d|\n", i);
			}
			ft_printf("showing stack A!!!!!!!\n");
			print_list(&st_a);
			ft_printf("showing STACK B????????\n");
			print_list(&st_b);
		}
		else
		{
			ft_printf("Error\n");
		}
	}
	else
		ft_printf("usage: stdin instruction | ./checker <argument integer>\n");
	return (0);
}
