/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:29:58 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/02 21:28:44 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "pushswap.h"

void	ra(t_stack *stack_a)
{
	int	i;
	int	data;

	if (stack_a == NULL)
		return ;
	if (stack_a->curr_cnt > 1)
	{
		i = stack_a->curr_cnt;
		data = stack_a->data[stack_a->top];
		while (--i)
			stack_a->data[i] = stack_a->data[i - 1];
		stack_a->data[0] = data;
	write(1, "ra\n", 3);
	}
}

void	rb(t_stack *stack_b)
{
	int	i;
	int	data;

	if (stack_b == NULL)
		return ;
	if (stack_b->curr_cnt > 1)
	{
		i = stack_b->curr_cnt;
		data = stack_b->data[stack_b->top];
		while (--i)
			stack_b->data[i] = stack_b->data[i - 1];
		stack_b->data[0] = data;
		write(1, "rb\n", 3);
	}
}

void	rr(t_stack *stack_a, t_stack *stack_b)
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
}