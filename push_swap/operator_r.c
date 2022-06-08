/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:29:58 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/08 11:43:11 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "pushswap.h"

int	ra(t_stack *stack_a)
{
	int	i;
	int	data;

	if (stack_a == NULL)
		return (0);
	if (stack_a->curr_cnt > 1)
	{
		i = stack_a->curr_cnt;
		data = stack_a->data[stack_a->top];
		while (--i)
			stack_a->data[i] = stack_a->data[i - 1];
		stack_a->data[0] = data;
		write(1, "ra\n", 3);
	}
	return (1);
}

int	rb(t_stack *stack_b)
{
	int	i;
	int	data;

	if (stack_b == NULL)
		return (0);
	if (stack_b->curr_cnt > 1)
	{
		i = stack_b->curr_cnt;
		data = stack_b->data[stack_b->top];
		while (--i)
			stack_b->data[i] = stack_b->data[i - 1];
		stack_b->data[0] = data;
		write(1, "rb\n", 3);
	}
	return (1);
}

int	rr(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	data;

	if (stack_a->curr_cnt > 1)
	{
		i = stack_a->curr_cnt;
		data = stack_a->data[stack_a->top];
		while (--i)
			stack_a->data[i] = stack_a->data[i - 1];
		stack_a->data[0] = data;
	}
	if (stack_b->curr_cnt > 1)
	{
		i = stack_b->curr_cnt;
		data = stack_b->data[stack_b->top];
		while (--i)
			stack_b->data[i] = stack_b->data[i - 1];
		stack_b->data[0] = data;
	}
	if (stack_a->curr_cnt > 1 || stack_b->curr_cnt > 1)
		write(1, "rr\n", 3);
	return (1);
}
