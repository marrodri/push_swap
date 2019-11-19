
#include "push_swap.h"

// unfinished TODO
int stBRotSort(t_app *app, t_list *st_b)
{
	t_list *head;
	int prev_val;
	int low_val;

	low_val = stck_lowVal(st_b);
	head = st_b;
	while (st_b->elem != app->stck_b_hi_val)
		st_b = st_b->next;
	prev_val = st_b->elem;
	st_b = st_b->next;
	if(!st_b)
		st_b = head;
	if(st_b->elem != low_val)
		return 0;
	while(1)
	{
		if (!st_b)
			st_b = head;
		if (st_b->elem == app->stck_b_hi_val)
			break;
		if (prev_val < st_b->elem && prev_val != app->stck_b_hi_val 
			&& (st_b->elem != low_val))
			return (0);
		prev_val = st_b->elem;
		st_b = st_b->next;
	}
	return (1);

}

//still buggy, segfault probably here!
int stARotSort(t_app *app, t_list *st_a)
{
	t_list *head;
	int prev_val;
	int low_val;

	low_val = stck_lowVal(st_a);
	head = st_a;
	while (st_a->elem != app->stck_a_hi_val)
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
		if (st_a->elem == app->stck_a_hi_val)
			break;
		if (prev_val > st_a->elem && prev_val != app->stck_a_hi_val 
			&& (st_a->elem != low_val))
			return (0);
		prev_val = st_a->elem;
		st_a = st_a->next;
	}
	return (1);
}
