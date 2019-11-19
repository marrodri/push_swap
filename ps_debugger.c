
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

void	print_stacks(t_list *st_a, t_list *st_b)
{
		ft_printf("===========\n");
		ft_printf("stack A:\n");
		print_stack(&st_a);
		ft_printf("-------------\n");
		ft_printf("stack B:\n");
		print_stack(&st_b);
		ft_printf("===end=====\n");
}

void	print_inst(t_app *app)
{
	ft_printf("ra:%d\n", app->sort_sta_flag[0]);
	ft_printf("rra:%d\n", app->sort_sta_flag[1]);
	ft_printf("sa:%d\n", app->sort_sta_flag[2]);
	ft_printf("pa:%d\n", app->sort_sta_flag[3]);
	ft_printf("rb:%d\n", app->sort_stb_flag[0]);
	ft_printf("rrb:%d\n", app->sort_stb_flag[1]);
	ft_printf("sb:%d\n", app->sort_stb_flag[2]);
	ft_printf("pb:%d\n", app->sort_stb_flag[3]);	
}
