/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:27:19 by marrodri          #+#    #+#             */
/*   Updated: 2019/09/30 14:27:20 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ch_next_low_elem(t_list *stack, t_app *app)
{
	t_list	*tmp;
	int		prev_elem;

	if (stack == NULL || stack->next == NULL)
		return (0);
	tmp = stack;
	prev_elem = tmp->elem;
	tmp = tmp->next;
	if (tmp->elem < prev_elem)
		return (1);
	return (0);
}

int		ch_first_hi_elem(t_list *stack, t_app *app)
{
	t_list	*tmp;
	// int		rot;
	int		high_elem;

	if (stack == NULL || stack->next == NULL || app->len_stck <= 2)
		return (0);
	tmp = stack;
	high_elem = tmp->elem;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->elem < high_elem)
		return (1);
	return (0);
}

int		ch_last_low_elem(t_list *stack, t_app *app)
{
	t_list	*tmp;
	t_list	*head;
	int		low_elem;

	if (stack == NULL || stack->next == NULL || app->len_stck <= 2)
		return (0);
	tmp = stack;
	head = stack;
	while (tmp->next)
		tmp = tmp->next;
	low_elem = tmp->elem;
	tmp = head;
	while (tmp)
	{
		// ft_printf("tmp elem is |%d|\n", tmp->elem);
		if (tmp->elem < low_elem)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		ch_special_case(t_list *stack, t_app *app)
{

}