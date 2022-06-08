/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:59:52 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/08 20:10:57 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pushswap.h"

void	init_sort(t_stack *stack_a, t_sort *sort, int len)
{
	sort->len = len;
	sort->arr = stack_to_array(stack_a, len);
	if (sort->arr == NULL)
		return ;
	sort->p1 = sort->arr[sort->len / 3];
	sort->p2 = sort->arr[sort->len * 2 / 3];
	sort->ra = 0;
	sort->rb = 0;
	sort->pa = 0;
	sort->pb = 0;
}

static	int	recur_b(t_stack *stack_a, t_stack *stack_b, t_sort *sort, int len)
{
	int	error;

	error = 0;
	while (len--)
	{
		if (stack_a->data[stack_a->top] < sort->p2)
		{
			sort->pb += pb(stack_a, stack_b);
			if (stack_b->data[stack_b->top] >= sort->p1 && \
			stack_b->data[stack_b->top] < sort->p2)
				sort->rb += rb(stack_b);
		}
		else
			sort->ra += ra(stack_a);
	}
	oper_rrr(stack_a, stack_b, *sort);
	if (quick_b(stack_a, stack_b, sort->ra))
		error = 1;
	if (quick_a(stack_a, stack_b, sort->rb))
		error = 1;
	if (quick_a(stack_a, stack_b, sort->pb - sort->rb))
		error = 1;
	return (error);
}

int	quick_b(t_stack *stack_a, t_stack *stack_b, int len)
{
	t_sort	sort;
	int		error;

	error = 0;
	init_sort(stack_a, &sort, len);
	if (sort.arr == NULL)
		return (1);
	if (sort.len < 4)
		small_sort(stack_a, stack_b, len);
	else
		error = recur_b(stack_a, stack_b, &sort, len);
	free(sort.arr);
	return (error);
}

static	int	recur_a(t_stack *stack_a, t_stack *stack_b, t_sort *sort, int len)
{
	int	error;

	error = 0;
	while (len-- && sort->len > 2)
	{
		if (stack_b->data[stack_b->top] >= sort->p1)
		{
			sort->pa += pa(stack_a, stack_b);
			if (stack_a->data[stack_a->top] < sort->p2 && \
			stack_a->data[stack_a->top] >= sort->p1)
				sort->ra += ra(stack_a);
		}	
		else
			sort->rb += rb(stack_b);
	}
	if (quick_b(stack_a, stack_b, sort->pa - sort->ra))
		error = 1;
	oper_rrr(stack_a, stack_b, *sort);
	if (quick_b(stack_a, stack_b, sort->pa - sort->ra))
		error = 1;
	if (quick_a(stack_a, stack_b, sort->rb))
		error = 1;
	return (error);
}

int	quick_a(t_stack *stack_a, t_stack *stack_b, int len)
{
	t_sort	sort;
	int		error;

	error = 0;
	init_sort(stack_b, &sort, len);
	if (sort.arr == NULL)
		return (1);
	if (sort.len < 4)
		small_sort_b(stack_a, stack_b, len);
	else
		error = recur_a(stack_a, stack_b, &sort, len);
	free(sort.arr);
	return (error);
}
