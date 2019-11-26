

#include "push_swap.h"

int lowerThan(int a, int b)
{
	return (a < b);
}

int higherThan(int a, int b)
{
	return (a > b);
}

//DONE, test more later
int stcka_midValComp(t_list *stck, int val)
{
	int newValLim;
	int valLim;
	t_list *head;

	head = stck;
	valLim = stck_hiVal(stck);
	newValLim = stck_hiVal(stck);
	if (val < stck_lowVal(stck))
		return (stck_lowVal(stck));
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

//DONE, test more later
int stckb_midValComp(t_list *stck, int val)
{
	int newValLim;
	int valLim;
	t_list *head;

	head = stck;
	valLim = stck_lowVal(stck);
	newValLim = stck_lowVal(stck);
	if (val > stck_hiVal(stck))
		return (stck_hiVal(stck));
	while (stck)
	{	
		if(val > stck->elem && stck->elem > valLim)
		{
			valLim = stck->elem;
		}
		stck = stck->next;
	}
	return (valLim);
}