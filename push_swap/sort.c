#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "pushswap.h"

int bubble_sort(int *arr, int len)// 오름차순
{
	int	i;
	int	j;
	int	tmp;

	if (arr == NULL)
		return (0);
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j + 1 < len)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	return (1);
}

int	issorted(t_l_stack *stack)
{
	int	i;

	if (stack == NULL)
		return (FALSE);
	i = -1;
	while (++i < stack->curr_cnt)
	{
		if (stack->data[i] <= stack->data[i + 1]
			return (FALSE);
	}
	return (TRUE);
}