/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:59:42 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/08 16:09:46 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	arg3sort(t_stack *stack_a, int len)
{
	if (len == 2)
	{
		if (stack_a->data[0] < stack_a->data[1])
			sa(stack_a);
	}
	if (len == 3)
	{
		while (stack_a->data[0] < stack_a->data[1] || stack_a->data[0] < stack_a->data[2])
			ra(stack_a);
		if (stack_a->data[1] < stack_a->data[2])
			sa(stack_a);
	}
}

void	small_sort(t_stack *stack_a, t_stack *stack_b, int len)
{
	if (len == 2)
	{
		if (stack_a->data[stack_a->top - 1] < stack_a->data[stack_a->top])
			sa(stack_a);
	}
	if (len == 3 && !isascend_from_top(stack_a, 3))
	{
		if (stack_a->data[stack_a->top - 1] < stack_a->data[stack_a->top])
			sa(stack_a);
		if (isascend_from_top(stack_a, 3))
			return ;
		pb(stack_a, stack_b);
		if (stack_a->data[stack_a->top - 1] < stack_a->data[stack_a->top])
			sa(stack_a);
		pa(stack_a, stack_b);
		if (stack_a->data[stack_a->top - 1] < stack_a->data[stack_a->top])
			sa(stack_a);
	}
}

void	small_sort_b(t_stack * stack_a, t_stack *stack_b, int len)
{
	int	cnt;

	cnt = 0;
	if (len == 1)
		pa(stack_a, stack_b);
	if (len == 2)
	{
		if (stack_b->data[stack_b->top - 1] > stack_b->data[stack_b->top])
			sb(stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	if (len == 3)
	{
		if (stack_b->data[stack_b->top - 1] > stack_b->data[stack_b->top])
			sb(stack_b);
		pa(stack_a, stack_b);
		if (stack_b->data[stack_b->top - 1] > stack_b->data[stack_b->top])
			sb(stack_b);
		pa(stack_a, stack_b);
		if (stack_a->data[stack_a->top - 1] < stack_a->data[stack_a->top])
			sa(stack_a);
		pa(stack_a, stack_b);
	}
}