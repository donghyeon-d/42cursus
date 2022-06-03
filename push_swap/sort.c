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

int	issorted_bt(t_stack *stack)//bottom에서 top으로 갈수록 커짐
{
	int	i;

	if (stack == NULL)
		return (FALSE);
	if (stack->curr_cnt < 2)
		return (TRUE);
	i = -1;
	while (++i < stack->top)
	{
		if (stack->data[i] < stack->data[i + 1])
			return (FALSE);
	}
	return (TRUE);
}

int	issorted_tb(t_stack *stack)//top에서 bottom으로 갈수록 커짐
{
	int	i;

	if (stack == NULL)
		return (FALSE);
	if (stack->curr_cnt < 2)
		return (TRUE);
	i = -1;
	while (++i < stack->top)
	{
		if (stack->data[i] > stack->data[i + 1])
			return (FALSE);
	}
	return (TRUE);
}