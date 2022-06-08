/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:59:44 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/08 20:11:21 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pushswap.h"

int	quick_util(t_stack *stack_a, t_stack *stack_b, int len)
{
	t_sort	sort;
	int		error;

	init_sort(stack_a, &sort, len);
	if (sort.arr == NULL)
		return (1);
	error = 0;
	while (len--)
	{
		if (stack_a->data[stack_a->top] < sort.p2)
		{
			sort.pb += pb(stack_a, stack_b);
			if (stack_b->data[stack_b->top] < sort.p1)
				sort.rb += rb(stack_b);
		}
		else
			sort.ra += ra(stack_a);
	}
	error += quick_b(stack_a, stack_b, sort.ra);
	error += quick_a(stack_a, stack_b, sort.pb - sort.rb);
	error += quick_a(stack_a, stack_b, sort.rb);
	free(sort.arr);
	return (error);
}

int	quicksort(t_stack *stack_a, t_stack *stack_b)
{
	int	error;

	error = 0;
	if (stack_a->curr_cnt < 4)
		arg3sort(stack_a, stack_a->curr_cnt);
	if (!isascend_from_top(stack_a, stack_a->curr_cnt))
		error = quick_util(stack_a, stack_b, stack_a->curr_cnt);
	return (error);
}
