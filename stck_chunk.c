

#include "push_swap.h"

void setTopVal(t_app **app, t_list *st_a)
{
	int index;

	index = 0;
	if((*app)->sort_sta_flag[0] >= 0)
	{
		index = (*app)->sort_sta_flag[0];
	}
	else if ((*app)->sort_sta_flag[1] >= 0)
	{
		index = (*app)->len_stck - (*app)->sort_sta_flag[1];
	}

	(*app)->chunk_top_val = stck_indVal(st_a, index);
	ft_printf("top val is |%d|\n",(*app)->chunk_top_val);

}

//TODO finds which value, inside the range of the chunk,
//  to move to the top based from the bottom or top of the stack

/*
** it sets the number of instructions
** for pushing the top from stack a to 
** stack b at proper place
*/
//CHECKPOINT TODO HERE IMPORTANT
void sortChunkInst(t_app **app, t_list *st_a, t_list *st_b)
{
	int stHiLowInd;
	int stHiLowVal;

	(*app)->len_stck_b = ft_list_size(st_b);
	if(st_a && st_b)
	{
		stHiLowVal = stck_hiValComp(st_b, (*app)->chunk_top_val);
		stHiLowInd = stck_valInd(st_b, stHiLowVal);
		if (stHiLowInd > 0)
		{
			(*app)->sort_stb_flag[0] = stHiLowInd; //rb
			(*app)->sort_stb_flag[1] = (*app)->len_stck_b - stHiLowInd; //rrb
		}
	}
	if(!ft_arriszero((*app)->sort_sta_flag, 4))
		(*app)->sort_stb_flag[3] = 1;
	rotInstrCheck(app);
}

/*
** it finds the lowest number of instructions for
** moving the closest range value to the top
*/

void setChnkValTopInst(t_app **app, t_list *st_a)
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
	if(index_frst > 0)
		indexComp(app, index_frst, index_lst);
	setTopVal(app, st_a);
	
}

void chunk_instr(t_app **app, t_list *st_a, t_list *st_b)
{
	// TODO ADD THE FLAGS FOR ROTATING THE STACK, THEN PUSH THE STACK
	if ((*app)->len_stck > (*app)->chunk_len)
	{
		//NOTE, how to sort both at the same time?
		//CHECKPOINT TODO
		// start the stack B flags sorting, by
		// checking the top of stack a to push properly
		// to stack B
		if(!stBRotSort(st_b))
		{
			//CHECKPOINT HERE
			// the sort the stack b 
			//and deactivate the push to stack b;
			ft_printf("stack b is not properly sorted, sorting b\n");
			stb_flag(app, st_b);
			print_inst(*app);
			saInstrCheck(app);
			rotInstrCheck(app);
		}
		else
		{
			ft_printf("stack b IS properly sorted, setting new push\n");
			setChnkValTopInst(app, st_a);
			print_inst(*app);
			sortChunkInst(app, st_a, st_b);
			(*app)->sort_stb_flag[3] = 1;
		}
	}
	else
	{
		//change the algo for set_sort_flag
		// ft_printf("EVERYTHING IS READY LAST INSTRUCTIONS\n");
		set_sort_flag(app, st_a, st_b);
	}
}

//DONE, FIXED
// sets the lowest chunk val and the highest chunk val,
// base from chunk lenght
void setChunkRange(t_app **app, t_list *st_a)
{
	int i;
	int pre_val;

	i = 0;
	pre_val = 0;
	(*app)->chunk_low_val = stck_lowVal(st_a);
	(*app)->chunk_hi_val = 0;
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

void checkChunk(t_app **app, t_list *st_b)
{
	int i;
	
	(*app)->len_stck_b = ft_list_size(st_b);
	i = (*app)->chunk_ind;
	ft_printf("i is %d\n", i);
	ft_printf("i * chunk len is %d\n", (i * (*app)->chunk_len));
	ft_printf("len is %d\n", (*app)->len_stck_b);
	if ((i * (*app)->chunk_len) == (*app)->len_stck_b)
	{
		(*app)->chunkSet = 1;
		(*app)->chunk_ind++;


	}
}