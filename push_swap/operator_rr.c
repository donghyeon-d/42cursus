/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:30:35 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/08 16:13:42 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "pushswap.h"

int	rra(t_stack *stack_a)
{
	int	data;
	int	i;

	if (stack_a == NULL)
		return (0);
	if (stack_a->curr_cnt > 1)
	{
		data = stack_a->data[stack_a->bottom];
		i = -1;
		while (++i < stack_a->curr_cnt - 1)
			stack_a->data[i] = stack_a->data[i + 1];
		stack_a->data[stack_a->top] = data;
	write(1, "rra\n", 4);
	}
	return (1);
}

int	rrb(t_stack *stack_b)
{
	int	data;
	int	i;

	if (stack_b == NULL)
		return (0);
	if (stack_b->curr_cnt > 1)
	{
		data = stack_b->data[stack_b->bottom];
		i = -1;
		while (++i < stack_b->curr_cnt - 1)
			stack_b->data[i] = stack_b->data[i + 1];
		stack_b->data[stack_b->top] = data;
		write(1, "rrb\n", 4);
	}
	return (1);
}

int	rrr(t_stack *stack_a, t_stack *stack_b)
{
	int	data;
	int	i;

	if (stack_a->curr_cnt > 1)
	{
		data = stack_a->data[stack_a->bottom];
		i = -1;
		while (++i < stack_a->curr_cnt - 1)
			stack_a->data[i] = stack_a->data[i + 1];
		stack_a->data[stack_a->top] = data;
	}
	if (stack_b->curr_cnt > 1)
	{
		data = stack_b->data[stack_b->bottom];
		i = -1;
		while (++i < stack_b->curr_cnt - 1)
			stack_b->data[i] = stack_b->data[i + 1];
		stack_b->data[stack_b->top] = data;
	}
	if (stack_a->curr_cnt > 1 || stack_b->curr_cnt > 1)
		write(1, "rrr\n", 4);
	return (1);
}

int	oper_rrr(t_stack *stack_a, t_stack *stack_b, t_sort sort)
{
	int	ra_cnt;
	int rb_cnt;

	ra_cnt = sort.ra;
	rb_cnt = sort.rb;

	while (ra_cnt && rb_cnt)
	{
		rrr(stack_a, stack_b);
		ra_cnt--;
		rb_cnt--;
	}
	if (ra_cnt != 0)
		rra(stack_a);
	if (rb_cnt != 0)
		rrb(stack_b);
	return (1);
}
