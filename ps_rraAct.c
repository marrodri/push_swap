
#include "push_swap.h"

//it still rotates when the head is the lowest and the last stack is the highest 

// int sta_exception(t_list *st_a)
// {
// 	int low_val;
// 	int hi_val;

// 	hi_val = stck_hiVal(st_a);
// 	low_val = stck_lowVal(st_a);
// 	if(st_a->elem != low_val)
// 	{
// 		return 0;
// 	}
// 	while(st_a->next)
// 	{
// 		st_a = st_a->next;
// 	}
// 	if(st_a->elem == hi_val)
// 	{
// 		return 1;
// 	}
// 	return 0;
// }

int		ch_rra_sta(t_list *st_a)
{
	//TODO check how many instr. needed to rotate using only rra;
	// for checking the hi_elem with ra goes an additional step
	int i;
	int index;
	int prev_val;
	t_list *head;
	// 1-2-3-5-4-6-7
	i = 0;
	head = st_a;
	index = 0;
	while(st_a->next)
		st_a = st_a->next;
	while(st_a)
	{
		if(prev_val > st_a->elem)
		{
			index = i;
		}
		i++;
		prev_val = st_a->elem;
		st_a = st_a->next;
	}
	st_a = head;
	if(sta_exception(st_a) && index == 0)
	{
		return 0;
	}
	return (index + 1);
}