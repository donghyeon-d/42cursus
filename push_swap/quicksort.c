/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:33:32 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/01 17:22:13 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "pushswap.h"
#include "../ft_libft/libft.h"

static int	quick_b(t_stack *stack_a, t_stack *stack_b, int len)//from a to b // len = stack_a->curr_cnt
{
	int	*curr_arr;
	int	pivot1;
	int	pivot2;
	int count;
	
	count = 0;
	curr_arr = stack_to_array(stack_a, len);
	pivot1 = curr_arr[stack_a->curr_cnt / 3];
	pivot2 = curr_arr[stack_a->curr_cnt * 2 / 3];
	while (len--)
	{
		count += pb(stack_a, stack_b);
		if (stack_a->data[stack_a->top] > pivot2)
			rr(stack_a, stack_b);
		rb(stack_b);
		else if (stack_a->data[stack_a->top] > pivot1 && stack_a->data[stack_a->top] <= pivot2)
			count += pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	free(curr_arr);
	return (count);
}

static int	quick_a(t_stack *stack_a, t_stack *stack_b, int len)//from b to a // len = QA의 리턴값
{
	int	count;

	count = 0;
	while (len--)
		count += pa(stack_a, stack_b);
	return (count);
}

void	ft_quicksort(t_stack *stack_a, t_stack *stack_b, int len)
{
	int	count_qa;
	int	count_qb;

	count_qb = quick_b(stack_a, stack_b, len)
	if (!issorted(stack_a))
		ft_quicksort(stack_a, stack_b, stack_a->curr_cnt);
	count_qa = quick_a(stac_a, stack_b, count_qb);
	if (!issorted(stack_a))
		ft_quicksort(stack_a, stack_b, count_qa);
}
