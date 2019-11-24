
#include "push_swap.h"

// unfinished TODO
int stBRotSort(t_list *st_b)
{
	t_list *head;
	int prev_val;
	int low_val;
	int	hi_val;
	
	if(!st_b)
		return (1);
	low_val = stck_lowVal(st_b);
	hi_val = stck_hiVal(st_b);
	head = st_b;
	while (st_b->elem != low_val)
		st_b = st_b->next;
	prev_val = st_b->elem;
	st_b = st_b->next;
	if(!st_b)
		st_b = head;
	if(st_b->elem != hi_val)
		return 0;
	while(1)
	{
		if (!st_b)
			st_b = head;
		if (st_b->elem == low_val)
			break;
		if (prev_val < st_b->elem && prev_val != low_val 
			&& (st_b->elem != hi_val))
			return (0);
		prev_val = st_b->elem;
		st_b = st_b->next;
	}
	return (1);
}

// still buggy, segfault probably here!
int stARotSort(t_app *app, t_list *st_a)
{
	t_list *head;
	int prev_val;
	int low_val;
	int hi_val;
	app->stck_a_hi_val = 0;
	low_val = stck_lowVal(st_a);
	hi_val = stck_hiVal(st_a);
	head = st_a;
	while (st_a->elem != hi_val)
		st_a = st_a->next;
	prev_val = st_a->elem;
	st_a = st_a->next;
	if(!st_a)
		st_a = head;
	if(st_a->elem != low_val)
		return 0;
	while(1)
	{
		if (!st_a)
			st_a = head;
		if (st_a->elem == hi_val)
			break;
		if (prev_val > st_a->elem && prev_val != hi_val
			&& (st_a->elem != low_val))
			return (0);
		prev_val = st_a->elem;
		st_a = st_a->next;
	}
	return (1);
}
