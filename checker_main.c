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
	ft_printf("######printing session########\n");
	while(tmp)
	{
		ft_printf("num is |%d|\n", tmp->elem);
		tmp = tmp->next;
	}
	ft_printf("^^^^^EXIT CHECK^^^^^^^\n");
}



int main(int argc, char **argv)
{
	t_list	*st_a;
	t_list	*st_b;
	t_app	*app;

	st_a = NULL;
	st_b = NULL;
	app = malloc(sizeof(t_app));
	if (argc >= 2)
	{
		if (set_int_arr(argv, argc, &app) && set_instr(0, &app))
		{
			set_stack(&st_a, app, app->arr_num);
			// print_list(&st_a);
			sort_stacks(st_a, st_b, app->instr);

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
