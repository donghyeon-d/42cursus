/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:33:03 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/08 17:30:32 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#define NULL 0

int	bubble_sort(int *arr, int len)
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

int	isascend_from_top(t_stack *stack, int len)
{
	int	i;

	if (stack == NULL)
		return (FALSE);
	if (stack->curr_cnt < 2)
		return (TRUE);
	i = -1;
	while (++i < len - 1)
	{
		if (stack->data[stack->top - i] > stack->data[stack->top - 1 - i])
			return (FALSE);
	}
	return (TRUE);
}


int	isdesend_from_top(t_stack *stack, int len)
{
	int	i;

	if (stack == NULL)
		return (FALSE);
	if (stack->curr_cnt < 2)
		return (TRUE);
	i = -1;
	while (++i < len - 1)
	{
		if (stack->data[stack->top - i] < stack->data[stack->top - 1 - i])
			return (FALSE);
	}
	return (TRUE);
}
