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
	(*app)->free_av = 0;
}

int main(int argc, char **argv)
{
	t_list	*st_a;
	t_list	*st_b;
	t_app	*app;
	int		i;

	st_a = NULL;
	st_b = NULL;
	i = 0;
	init_app(&app);
	if (check_arg(argv, argc, &app))
	{
		if (set_instr(0, &app))
		{
			ft_printf("here!\n");
			set_stack(&st_a, app);
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
	}
	else
		ft_printf("Error\n");
	free
	free(app->arr_num);
	free_words(app->instr);
	if(app->free_av)
		free_words(app->av); //doesnt need to free if there's more than 2 args
	free(app);
	free_list(&st_a);
	free_list(&st_b);
	system("leaks checker");
	return (0);
}
