

#include "push_swap.h"

//TODO finds which value, inside the range of the chunk,
//  to move to the top based from the bottom or top of the stack

// CHECKPOINT

void sortChunk(t_app **app, t_list *st_a)
{
	t_list *head;
	int frstIntFlag;
	int i;
	int index_frst;
	int index_lst;

	frstIntFlag = 0;
	head = st_a;
	i = 0;
	index_frst = 0;
	index_lst = 0;
	while (st_a)
	{
		if ((*app)->chunk_hi_val >= st_a->elem 
		&& (*app)->chunk_low_val <= st_a->elem && !frstIntFlag)
		{
			index_frst = i;
			frstIntFlag = 1;
		}
		if ((*app)->chunk_hi_val >= st_a->elem 
		&& (*app)->chunk_low_val <= st_a->elem)
		{
			index_lst = i;
		}
		i++;
		st_a = st_a->next;
	}
	st_a = head;
	ft_printf("first index %d\n", index_frst);
	ft_printf("last index %d\n", index_lst);

}

void chunk_instr(t_app **app, t_list *st_a, t_list *st_b)
{
	//TODO ADD THE FLAGS FOR ROTATING THE STACK, THEN PUSH THE STACK

	if((*app)->len_stck > (*app)->chunk_len)
	{
		sortChunk(app, st_a);
	}
	else
	{
		set_sort_flag(&app, st_a, st_b);
	}
}



//TODO sets the lowest chunk val and the highest chunk val,
// base from chunk lenght;
//DONE
void setChunkRange(t_app **app, t_list *st_a)
{
	int i;
	int pre_val;

	i = 0;
	pre_val = 0;
	(*app)->chunk_hi_val = 0;
	(*app)->chunk_low_val = stck_lowVal(st_a);
	while(i < (*app)->chunk_len)
	{
		(*app)->chunk_hi_val = stck_hiValComp(st_a, pre_val);
		pre_val = (*app)->chunk_hi_val;
		i++;
	}
	(*app)->chunkSet = 0;
	ft_printf("lowest chunk val is |%d|\n",(*app)->chunk_low_val);
	ft_printf("highest chunk val is |%d|\n",(*app)->chunk_hi_val);
}



//TODO sets the length of chunk based from the length of the stack
//DONE
void setChunkLen(t_app **app, t_list  *st_a)
{
	(*app)->len_stck = ft_list_size(st_a);
	if((*app)->len_stck > 10)
	{
		(*app)->chunk_len = (*app)->len_stck / 5;
	}
}