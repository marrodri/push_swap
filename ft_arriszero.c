
#include "libft/libft.h"

int		ft_arriszero(int *num, int size)
{
	int i;

	i = 0;
	while(i < size)
	{
		if(num[i])
			return (0);
		i++;
	}
	return (1);
}