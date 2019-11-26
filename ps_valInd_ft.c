/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_valInd_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 00:43:17 by marrodri          #+#    #+#             */
/*   Updated: 2019/11/09 00:43:21 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stck_lowVal(t_list *stck)
{
	int low_val;

	low_val = stck->elem;
	while (stck)
	{
		if (stck->elem < low_val)
			low_val = stck->elem;
		stck = stck->next;
	}
	return (low_val);
}

int	stck_hiVal(t_list *stck)
{
	int hi_val;

	hi_val = stck->elem;
	while (stck)
	{
		if (stck->elem > hi_val)
			hi_val = stck->elem;
		stck = stck->next;
	}
	return (hi_val);
}

int stck_indVal(t_list *stck, int index)
{
	int i;

	i = 0;
	while(i < index)
	{
		stck = stck->next;
		i++;
	}
	if(!stck)
		return 0;
	return stck->elem;
}

int stck_valInd(t_list *stck, int elem)
{
	int i;
	int index;
	i = 0;
	index = -1;
	while (stck)
	{
		if (stck->elem == elem)
			index = i;
		stck = stck->next;
		i++;
	}
	return (index);
}
