
#include "push_swap.h"

/*
** compare the number of rots to reach the top and set the
** lowest number possible to rotate from stack_a
*/

void indexComp(t_app **app, int frstIndex, int lastIndex)
{
	int raInstCount;
	int rraInstCount;
	int midpoint;

	midpoint = (*app)->len_stck / 2;
	raInstCount = 0;
	rraInstCount = 0;
	if(frstIndex <= midpoint)
	{
		raInstCount = frstIndex;
	}
	if(lastIndex > midpoint)
	{
		rraInstCount = (*app)->len_stck - lastIndex;
	}
	(*app)->sort_sta_flag[0] = raInstCount;
	(*app)->sort_sta_flag[1] = rraInstCount;
	rotInstrCheck(app);
}

void	rotInstrCheck(t_app **app)
{
	if((*app)->sort_sta_flag[0] > (*app)->sort_sta_flag[1] && 
	(*app)->sort_sta_flag[1] > 0)
	{
		(*app)->sort_sta_flag[0] = 0;
	}
	else if ((*app)->sort_sta_flag[0] <= (*app)->sort_sta_flag[1] &&
		(*app)->sort_sta_flag[0] > 0)
	{
		(*app)->sort_sta_flag[1] = 0;
	}
	if((*app)->sort_stb_flag[0] > (*app)->sort_stb_flag[1] && 
		(*app)->sort_stb_flag[1] > 0)
	{
		(*app)->sort_stb_flag[0] = 0;
	}
	else if((*app)->sort_stb_flag[0] <= (*app)->sort_stb_flag[1] &&
		(*app)->sort_stb_flag[0] > 0)
	{
		(*app)->sort_stb_flag[1] = 0;
	}
}
