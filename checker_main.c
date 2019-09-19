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

int main()
{
	t_list *stack_a;
	t_list *stack_b;

	//sets the stack a from args readed
	//reads from the stdin the instruction set and the args
	// each instruction is separated by a new line
	//it will read sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr

	// if there isn't any duplicate or a different character than a number, or an
	// unrecognized instruction from stdin, enters the process; if not skip the 
	// the proccess, displays ERROR and close the program
		//sorts the stack a, based from the instructions list,
		//it will be iterated until the list reach to the end point 
		//checks stack_a if its sorted and stack b if its empty
			//if true print OK
		// else print KO

	return (0);
}
