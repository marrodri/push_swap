
#include "push_swap.h"

// void rraComp(t_app **app, int frstIndRraInst, int lastIndRraInst)
// {
// 	if(frstIndRraInst < 0)
// 		frstIndRraInst = 0;
// 	if(lastIndRraInst < 0)
// 		lastIndRraInst = 0;
// 	if(frstIndRraInst >= lastIndRraInst)
// 		(*app)->sort_sta_flag[1] = lastIndRraInst;
// 	else if(frstIndRraInst < lastIndRraInst)
// 		(*app)->sort_sta_flag[1] = frstIndRraInst;

// }

// void raComp(t_app **app, int frstIndRaInst, int lastIndRaInst)
// {
// 	if(frstIndRaInst <= 0)
// 	{
// 		frstIndRaInst = 0;
// 		lastIndRaInst = 0;
// 	}
// 	if(lastIndRaInst <= 0)
// 		lastIndRaInst = 0;
// 	if(frstIndRaInst >= lastIndRaInst)
// 		(*app)->sort_sta_flag[0] = lastIndRaInst;
// 	else if(frstIndRaInst < lastIndRaInst)
// 		(*app)->sort_sta_flag[0] = frstIndRaInst;
	
// }

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

	// frstIndRaInst = frstIndex;
	// frstIndRraInst = (*app)->len_stck - frstIndex;
	// lastIndRaInst = lastIndex;
	
	
	// ft_printf("frstIndRaInst|%d|\n", frstIndRaInst);
	// ft_printf("frstIndRraInst|%d|\n", frstIndRraInst);
	// ft_printf("lastIndRaInst|%d|\n", lastIndRaInst);
	// ft_printf("lastIndRraInst|%d|\n", lastIndRraInst);
	// raComp(app, frstIndRaInst, lastIndRaInst);
	// rraComp(app, frstIndRraInst, lastIndRraInst);
	(*app)->sort_sta_flag[0] = raInstCount;
	(*app)->sort_sta_flag[1] = rraInstCount;
	rotInstrCheck(app);
	ft_printf("INDEX COMP INSTR ARE!!!\n");
	print_inst(*app);
}

//remodify this one
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
