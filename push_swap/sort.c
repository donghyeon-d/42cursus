#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "pushswap.h"

int argsort(int *argument, int argc)
{
	int	i;
	int	j;
	int	tmp;

	if (int == NULL)
		return (0);
	i = -1;
	while (++i < argc - 2)
	{
		j = -1;
		while (++j < argc - 2)
		{
			if (argument[i + j] > argument[i + j + 1])
			{
				tmp = argument[i + j];
				argument[i + j] = argument[i + j + 1];
				argument[i + j + 1] = tmp;
			}
		}
	}
	return (1);
}

void	ft_pushswap(t_l_stack *stack_a, t_l_stack *stack_b, int *argument, int argc)
{
	int pivot1;
	int pivot2;
	int	i;
	int	circul;

	pivot1 = argument[(argc - 1) / 2];
	pivot2 = argument[(argc - 1) / 3];
	i = -1;
	circul = (argc - 1) / 2;
	while (stack_a->currentcount > 3)
	{
		while (++i < circul)
		{
			if (stack_a->top > pivot1)
				pb(stack_a, stack_b);
			if (stack_b->top < pivot2)
				rb(stack_b);
		}
	}
}