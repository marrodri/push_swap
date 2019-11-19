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

//DONE, test more later
int stck_hiValComp(t_list *stck, int val)
{
	int newValLim;
	int valLim;
	t_list *head;

	head = stck;
	valLim = stck_hiVal(stck);
	newValLim = stck_hiVal(stck);
	if (val < stck_lowVal(stck))
		return stck_lowVal(stck);
	while (1)
	{	
		if(!stck)
		{
			stck = head;
			if(newValLim < valLim)
				valLim = newValLim;
			else
				break;
		}
		if (stck->elem > val && stck->elem < valLim)
		{
			newValLim = stck->elem;
		}
		stck = stck->next;
	}
	return (valLim);
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

// int stck_midVal(t_list *stck)
// {
// 	int mid_val;
// 	int low_val;
// 	int mid_len;
// }

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
