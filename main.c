

#include "push_swap.h"

#include "stdio.h"
int main(int argc, char **argv)
{
	int a = ft_atoi(argv[1]);
	long int b;
	b = (long int)a;
	ft_printf("int |%d|\n", a);
	ft_printf("long int is |%ld|\n", b);
	//max_limit is 9 integers, 
	if(b > 2147483647 || b < -214783648)
	{
		ft_printf("int is beyond limit\n");
	}
	// sleep(10);
	return 0;
}