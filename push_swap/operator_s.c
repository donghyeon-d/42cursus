/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:32:20 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/04 15:32:23 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "pushswap.h"

int	sa(t_stack *stack_a)
{
	int	data;

	if (stack_a == NULL || stack_a->curr_cnt < 2)
		return (0);
	data = stack_a->data[stack_a->top];
	stack_a->data[stack_a->top] = stack_a->data[stack_a->top - 1];
	stack_a->data[stack_a->top - 1] = data;
	write(1, "sa\n", 3);
	return (1);
}

int	sb(t_stack *stack_b)
{
	int	data;

	if (stack_b == NULL || stack_b->curr_cnt < 2)
		return (0);
	data = stack_b->data[stack_b->top];
	stack_b->data[stack_b->top] = stack_b->data[stack_b->top - 1];
	stack_b->data[stack_b->top - 1] = data;
	write(1, "sb\n", 3);
	return (1);
}

int	ss(t_stack *stack_a, t_stack *stack_b)
{
	int	data;

	if (stack_a == NULL || stack_a->curr_cnt < 2)
		return (0);
	if (stack_b == NULL || stack_b->curr_cnt < 2)
		return (0);
	data = stack_a->data[stack_a->top];
	stack_a->data[stack_a->top] = stack_a->data[stack_a->top - 1];
	stack_a->data[stack_a->top - 1] = data;
	data = stack_b->data[stack_b->top];
	stack_b->data[stack_b->top] = stack_b->data[stack_b->top - 1];
	stack_b->data[stack_b->top - 1] = data;
	write(1, "ss\n", 3);
	return (1);
}
