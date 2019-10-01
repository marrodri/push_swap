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
	(*app)->av = NULL;
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
	int		i;

	st_a = NULL;
	st_b = NULL;
	init_app(&app);

	i = 0;
	if (argc >= 1)
	{
		if (set_int_arr(argv, argc, &app) && set_instr(0, &app))
		{
			set_stack(&st_a, app);
			// free(app->arr_num);
			while (app->instr[i])
			{
				ft_printf("int i |%d|\n", i);
				sort_stacks(&st_a, &st_b, app->instr[i]);
				i++;
			}
			if (check_stacks(st_a, st_b))
				ft_printf("OK\n");
			else
				ft_printf("KO\n");
			
		}
		else
			ft_printf("Error\n");
		free_words(app->instr);
		
		free(app);
		free_list(&st_a);
		free_list(&st_b);
		// sleep(5);
	}
	// system("leaks checker");
	return (0);
}

//IMPORTANT sa, ra, rra, sa input show error