

#include "push_swap.h"

void swapComp(t_app **app, t_list *st_a)
{
	int ra_inst;
	int rra_inst;
	int first_fl;
	int i;

	st_a = st_a->next->next;
	first_fl = 0;
	i = 2;
	while(st_a)
	{
		if(st_a->elem >= (*app)->chunk_low_val 
			&& st_a->elem <= (*app)->chunk_top_val && !first_fl)
		{
			ra_inst = i - 1;
			first_fl = 1;
		}
		if(st_a->elem >= (*app)->chunk_low_val 
			&& st_a->elem <= (*app)->chunk_top_val)
		{
			rra_inst = ((*app)->len_stck - i) + 2;
		}
		i++;
		st_a = st_a->next;
	}
	if(ra_inst <= rra_inst)
	{
		(*app)->sort_sta_flag[1] = 1; //ra
	}
	else if(ra_inst >= rra_inst)
	{
			(*app)->sort_sta_flag[0] = 1; //sa
	}
	//if at the beggining of the stack there
	//is another value of the range much closer
	//than the end of the stack, then go RA,
	//else at the end of the stack there is a closer
	// value to move than the beggining of the stack
	//then SA

}

void setTopVal(t_app **app, t_list *st_a)
{
	int index;

	index = 0;
	if((*app)->sort_sta_flag[0] > 0 && (*app)->sort_sta_flag[1] == 0)
	{
		index = (*app)->sort_sta_flag[0];
	}
	else if ((*app)->sort_sta_flag[1] > 0 && (*app)->sort_sta_flag[0] == 0)
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
// void sortChunkInst(t_app **app, t_list *st_a, t_list *st_b)
// {
// 	int ind;
// 	int stHiLowVal;
// 	int hiVal;
// 	int lowVal;
// 	// int stb_len;

// 	if(st_a && st_b)
// 	{
// 		(*app)->len_stck_b = ft_list_size(st_b);
// 		stHiLowVal = stck_hiValComp(st_b, (*app)->chunk_top_val);
// 		hiVal = stck_hiVal(st_b);
// 		lowVal = stck_lowVal(st_b);
// 		ft_printf("chunk top val is %d\n", (*app)->chunk_top_val);
// 		ft_printf("hi low is %d\n", stHiLowVal);
// 		if((*app)->chunk_top_val > hiVal)
// 		{
// 			//set to the highest position of the stack b
// 			ind = stck_valInd(st_b, hiVal);
// 			(*app)->sort_stb_flag[0] = ind; //rb
// 			(*app)->sort_stb_flag[1] = (*app)->len_stck_b - ind; //rrb
// 		}
// 		//else if the top_val is lower than the lowest val
// 		else if((*app)->chunk_top_val < lowVal)
// 		{
// 			//set to the lowest position of the stack b
// 			ind = stck_valInd(st_b, lowVal);
// 			(*app)->sort_stb_flag[0] = ind; //rb
// 			(*app)->sort_stb_flag[1] = (*app)->len_stck_b - ind; //rrb
// 		}
// 		else
// 		{
// 			//else do the normal rotation
// 			ind = stck_valInd(st_b, stHiLowVal);
// 			ft_printf("hi low index is %d\n", ind);
// 			if (ind > 0)
// 			{
// 				// (*app)->sort_stb_flag[0] = ind + 1; //rb
// 				// (*app)->sort_stb_flag[1] = ((*app)->len_stck_b - ind) - 1; //rrb
// 				(*app)->sort_stb_flag[0] = ind; //rb
// 				(*app)->sort_stb_flag[1] = (*app)->len_stck_b - ind; //rrb
// 			}
// 		}
// 		ft_printf("stb_flag[0] %d\n",(*app)->sort_stb_flag[0]);
// 		ft_printf("stb_flag[1] %d\n",(*app)->sort_stb_flag[1]);	
// 	}
// 	rotInstrCheck(app);
// }

//CHECKPOINT HERE IMPORTANT
void sortChunkInst(t_app **app, t_list *st_a, t_list *st_b)
{
	int ind;
	int stHiLowVal;
	int stb_len;
	if(st_a && st_b)
	{
		stb_len = ft_list_size(st_b);
		stHiLowVal = stckb_midValComp(st_b, (*app)->chunk_top_val);
		ind = stck_valInd(st_b, stHiLowVal);
		ft_printf("chunk top val is %d\n", (*app)->chunk_top_val);
		ft_printf("hi low is %d\n", stHiLowVal);
		ft_printf("hi low index is %d\n", ind);
		// if (ind == 0 && st_b->elem > (*app)->chunk_top_val
		// && st_b->next->elem < (*app)->chunk_top_val)
		// {
		// 	(*app)->sort_stb_flag[0] = 1;
		// }
		// else
		// {
			(*app)->sort_stb_flag[0] = ind; //rb
			(*app)->sort_stb_flag[1] = ((*app)->len_stck_b - ind); //rrb
		// }
		if((*app)->sort_stb_flag[1] == stb_len)
			(*app)->sort_stb_flag[1] = 0;
		
		ft_printf("stb_flag[0] %d\n",(*app)->sort_stb_flag[0]);
		ft_printf("stb_flag[1] %d\n",(*app)->sort_stb_flag[1]);
			
			
	}
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
	if(index_frst == 1)
	{
		swapComp(app, st_a);
	}
	else if(index_frst > 0)
		indexComp(app, index_frst, index_lst);
	setTopVal(app, st_a);
	
}

void chunk_instr(t_app **app, t_list *st_a, t_list *st_b)
{
	if (stARotSort(*app, st_a))
	{
		ft_printf("EVERYTHING IS READY LAST INSTRUCTIONS\n");
		(*app)->lastSet = 1;
		// last pushes are buggy, try to fix this
		// set_sort_flag(app, st_a, st_b);
		setSortedInst(app, st_a, st_b);
		rotInstrCheck(app);
	}
	else if (!(*app)->lastSet)
	{
		setChnkValTopInst(app, st_a);
		if(!stBRotSort(st_b))
		{
			// sort the stack b if it's not sorted
			ft_printf("stack b is not properly sorted, sorting b\n");
			stb_flag(app, st_b);
			print_inst(*app);
			saInstrCheck(app);
			rotInstrCheck(app);
		}
		else
		{
			ft_printf("stack b IS properly sorted, setting new push\n");
			print_inst(*app);
			//CHECKPOINT HERE
			sortChunkInst(app, st_a, st_b);
			(*app)->sort_stb_flag[3] = 1;
		}
	}
}

// DONE, FIXED
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
		(*app)->chunk_hi_val = stcka_midValComp(st_a, pre_val);
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