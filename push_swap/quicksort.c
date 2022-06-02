/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:33:32 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/02 21:32:07 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "pushswap.h"
// #include "../ft_libft/libft.h"

static int	quick_b(t_stack *stack_a, t_stack *stack_b, int len)//from a to b // len = stack_a->curr_cnt
{
	int	*curr_arr;
	int	pivot1;
	int	pivot2;
	int count;
	
	count = 0;
	curr_arr = stack_to_array(stack_a, stack_a->curr_cnt);
	pivot1 = curr_arr[(stack_a->top + 1) / 3];
	pivot2 = curr_arr[(stack_a->top + 1) * 2 / 3];
	while (len--)
	{
		if (stack_a->data[stack_a->top] > pivot2)
			ra(stack_a);
		else if (stack_a->data[stack_a->top] > pivot1 && stack_a->data[stack_a->top] <= pivot2)
			count += pb(stack_a, stack_b);
		else
		{
			pb(stack_a, stack_b);
			if (stack_a->data[stack_a->top] <= pivot1)
				rr(stack_a, stack_b);
			else
				rb(stack_b);
		}
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
	if (stack_a->data[stack_a->top] > stack_b->data[stack_a->top - 1])
		sa(stack_a);
	return (count);
}

static void	small_sort(t_stack *stack_a, int len)
{
	if (len < 2)
		return ;
	if (len == 2)
	{
		if (stack_a->data[0] < stack_a->data[1])
			sa(stack_a);
		return ;
	}
	if (len == 3)
	{
		while (stack_a->data[0] < stack_a->data[1] || stack_a->data[0] < stack_a->data[2])
			ra(stack_a);
		if (stack_a->data[0] < stack_a->data[1])
			sa(stack_a);
		return ;
	}
}

void	ft_quicksort(t_stack *stack_a, t_stack *stack_b, int len)
{
	int	count_qa;
	int	count_qb;

	if (len < 4)
		return (small_sort(stack_a, len));
	count_qb = quick_b(stack_a, stack_b, len);
	if (!issorted(stack_a))
		ft_quicksort(stack_a, stack_b, stack_a->curr_cnt);
	count_qa = quick_a(stack_a, stack_b, count_qb);
	if (!issorted(stack_a))
		ft_quicksort(stack_a, stack_b, count_qa);
}