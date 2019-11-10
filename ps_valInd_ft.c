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

int	stck_lowValInd(t_list *stck)
{
	int i;
	int low_index;
	int low_val;

	i = 0;
	low_index = 0;
	low_val = stck->elem;
	while (!stck)
	{
		if (stck->elem < low_val)
		{
			low_val = stck->elem;
			low_index = i;
		}
		i++;
		stck = stck->next;
	}
	return (low_index);
}

int	stck_hiValInd(t_list *stck)
{
	int i;
	int hi_index;
	int hi_val;

	i = 0;
	hi_index = 0;
	hi_val = stck->elem;
	while (stck)
	{
		if (stck->elem > hi_val)
		{
			hi_val = stck->elem;
			hi_index = i;
		}
		stck = stck->next;
		i++;
	}
	return (hi_index);
}
