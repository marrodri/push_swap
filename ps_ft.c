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

//TODO add the set instructions for sorting algorithm
#include "push_swap.h"


//stack a should return 0, stack b should return 1
int		ch_next_hi_elem(t_list *stack)
{
	t_list	*tmp;
	int		prev_elem;

	if (stack == NULL || stack->next == NULL)
	{
		ft_printf("stack is null\n");
		return (-1);
	}
	tmp = stack;
	prev_elem = tmp->elem;
	tmp = tmp->next;
	if (tmp->elem > prev_elem)
		return (1);
	return (0);
}

int		ch_first_hi_elem(t_list *stack)
{
	t_list	*tmp;
	int		high_elem;

	if (stack == NULL || stack->next == NULL)
		return (-1);
	tmp = stack;
	high_elem = tmp->elem;
	while(tmp)
	{
		if(tmp->elem > high_elem)
			return 0;
		tmp = tmp->next;
	}
	return 1;
}

int		ch_last_hi_elem(t_list *stack)
{
	t_list	*tmp;
	t_list	*head;
	int		high_elem;

	if (stack == NULL || stack->next == NULL)
		return (-1);
	tmp = stack;
	head = stack;
	while(tmp->next)
		tmp = tmp->next;
	high_elem = tmp->elem;
	tmp = head;
	while(tmp)
	{
		if(tmp->elem > high_elem)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
