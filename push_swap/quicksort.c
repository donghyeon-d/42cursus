/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:33:32 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/03 12:15:51 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "pushswap.h"
// #include "../ft_libft/libft.h"
static int	quick_b(t_stack *stack_a, t_stack *stack_b, int len);
static int	quick_a(t_stack *stack_a, t_stack *stack_b, int len);
static void	small_sort(t_stack *stack_a, int len);
static int	small_sort_b(t_stack * stack_a, t_stack *stack_b, int len);

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
			count += pb(stack_a, stack_b);
			if (stack_a->data[stack_a->top] > pivot2)
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
	int	*curr_arr;
	int	pivot1;

	count = 0;
	if (len < 4)
		return (small_sort_b(stack_a, stack_b, stack_b->curr_cnt));
	curr_arr = stack_to_array(stack_b, stack_b->curr_cnt);
	pivot1 = curr_arr[(stack_b->top + 1) / 2];
	while (len--) // len 개수 3개 이하 일 때
	{
		if (stack_b->data[stack_b->top] > pivot1)
			count += pa(stack_a, stack_b);
		else
			rb(stack_b);
	}
	if (count == 2 && stack_a->data[stack_a->top] && stack_a->data[stack_a->top + 1])
		sa(stack_a);
	// printf("\n");
	free(curr_arr);
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

static int	small_sort_b(t_stack * stack_a, t_stack *stack_b, int len)
{
	if (len < 2)
	{
		pa(stack_a, stack_b);
		return (1);
	}
	if (len == 2)
	{
		if (stack_b->data[0] > stack_b->data[1])
			sb(stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		return (2);
	}
	if (len == 3)
	{
		while (stack_b->data[0] > stack_b->data[1] || stack_b->data[0] > stack_b->data[2])
			rb(stack_b);
		if (stack_b->data[1] > stack_b->data[2])
			sb(stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		return (3);
	}
	return (0);
}

void	ft_quicksort(t_stack *stack_a, t_stack *stack_b, int len)
{
	int	count_qa;
	int	count_qb;

	if (stack_a->curr_cnt < 4)
		small_sort(stack_a, stack_a->curr_cnt);
	if (issorted_bt(stack_a) && stack_b->curr_cnt == 0)
		return ;
	if (!issorted_bt(stack_a))
		count_qb = quick_b(stack_a, stack_b, len);
	if (!issorted_bt(stack_a))
		ft_quicksort(stack_a, stack_b, stack_a->curr_cnt);
	count_qa = quick_a(stack_a, stack_b, stack_b->curr_cnt);
	if (!issorted_bt(stack_a) || stack_b->curr_cnt)
		ft_quicksort(stack_a, stack_b, count_qa);
	// if (issorted_bt(stack_a) && stack_b->curr_cnt != 0)
		// count_qa = quick_a(stack_a, stack_b, stack_b->curr_cnt);
	// if (!issorted_bt(stack_a))
	// 	ft_quicksort(stack_a, stack_b, count_qa);
}

void	ft_quicksort(t_stack *stack_a, t_stack *stack_b, int len)
{
	int	count_qa;
	int	count_qb;
	
	if (stack_a->curr_cnt < 4)
		return (small_sort(stack_a, stack_a->curr_cnt));
	while (!issorted_bt(stack_a))
		quick_b(stack_a, stack_b, stack_a->curr_cnt);
	if (stack_a->curr_cnt != 0)
		count_qa = quick_a(stack_a, stack_b, stack_b->curr_cnt);
	if (!issorted_bt(stack_a) || stack_b->curr_cnt != 0)
		ft_quicksort(stack_a, stack_b, count_qa);
}