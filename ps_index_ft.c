
#include "push_swap.h"


int		stck_low_val(t_app **app, t_list *stck)
{
	(*app)->stck_ind = 0;
	(*app)->stck_a_low_val = stck->elem;
	while(!stck)
	{
		if(stck->elem < (*app)->stck_a_low_val)
		{
			(*app)->stck_a_low_val = stck->elem;
			(*app)->stck_a_low_val_ind = (*app)->stck_ind;
		}
		stck = stck->next;
		(*app)->stck_ind++;
	}
}

int	stck_hi_val(t_app **app, t_list *stck)
{
	int hi_val;

	hi_val = stck->elem;
	while (stck)
	{
		if (stck->elem > hi_val)
			hi_val = stck->elem;
		stck = stck->next;
	}
	return 0;
}

void	stck_low_valInd(t_app **app, t_list *stck)
{
	//get the lowest value of the stack and the index of the highest value
	(*app)->stck_ind = 0;
	(*app)->stck_a_low_val = stck->elem;
	while(!stck)
	{
		if(stck->elem < (*app)->stck_a_low_val)
		{
			(*app)->stck_a_low_val = stck->elem;
			(*app)->stck_a_low_val_ind = (*app)->stck_ind;
		}
		stck = stck->next;
		(*app)->stck_ind++;
	}
}

void	stck_hi_valInd(t_app **app, t_list *stck)
{
	//get the higest value of the stack and the index of the highest value
	(*app)->stck_ind = 0;
	(*app)->stck_a_hi_val = stck->elem;
	while (stck)
	{
		if (stck->elem > (*app)->stck_a_hi_val)
		{
			(*app)->stck_a_hi_val = stck->elem;
			(*app)->stck_a_hi_val_ind = (*app)->stck_ind;
		}
		stck = stck->next;
		(*app)->stck_ind++;
	}
}