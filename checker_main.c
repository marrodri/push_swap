/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:31:29 by marrodri          #+#    #+#             */
/*   Updated: 2019/09/19 16:31:31 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_arg(char **argv, t_psvar **psvar)
{
	//return 1 if there isn't any duplicate or 
	// a different character than a number, or goes the limit of int
	return 0;
}

int		read_instr(int fd, t_psvar **psvar)
{
	//reads from the stdin the instruction set and the args
	// each instruction is separated by a new line
	//it will read sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr
	// return  0 if unrecognized instruction from stdin, enters the process
	//or badly formatted
	return 0;
}

int main(int argc, char **argv)
{
	t_list *st_a;
	t_list *st_b;
	t_psvar *psvar;

	st_a = NULL;
	st_b = NULL;
	psvar = malloc(sizeof(t_psvar));
	if(argc >= 2)
	{
		//sets the stack a from args readed
		if(check_arg(argv, &psvar) && read_instr(0, &psvar))
		{
			//sorts the stack a, based from the instructions list,
			//it will be iterated until the list reach to the end point 
			//checks stack_a if its sorted and stack b if its empty
				//if true print OK
			// else print KO
		}
		else
		{
			// the proccess, displays ERROR and close the program
		}
	}
	else
	{
		ft_printf("usage: stdin instruction | ./checker <argument integer>\n");
	}

	return (0);
}
