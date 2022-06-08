#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "pushswap.h"

int	quick_a(t_stack *stack_a, t_stack *stack_b, int len);
int quick_b(t_stack *stack_a, t_stack *stack_b, int len);
// static int	small_sort(t_stack *stack_a, int len)
// {
// 	int	cnt;

// 	cnt = 0;
// 	if (len < 2)//
// 		return (0);//
// 	if (len == 2)
// 	{
// 		if (stack_a->data[stack_a->top - 1] < stack_a->data[stack_a->top])
// 			sa(stack_a);
// 	}
// 	if (len == 3)
// 	{
// 		while (stack_a->data[stack_a->top - 1] < stack_a->data[stack_a->top] && --len)
// 		{
// 			sa(stack_a);
// 			cnt += ra(stack_a);
// 		}
// 		while (cnt--)
// 			rra(stack_a);
// 		if (stack_a->data[stack_a->top - 1] < stack_a->data[stack_a->top])
// 			sa(stack_a);
// 	}
// 	return (cnt);
// }

static	void	small_sort(t_stack *stack_a, int len)
{
	int	cnt;

	cnt = 0;
	if (len == 2)
	{
		if (stack_a->data[stack_a->top - 1] < stack_a->data[stack_a->top])
			sa(stack_a);
	}
	if (len == 3)
	{
		while (!issorted_from_top(stack_a, 3))
		{
			if (stack_a->data[stack_a->top - 1] < stack_a->data[stack_a->top])
				cnt += ra(stack_a);
			if (stack_a->data[stack_a->top - 1] < stack_a->data[stack_a->top])
				sa(stack_a);
			if (cnt--)
				rra(stack_a);
			if (stack_a->data[stack_a->top - 1] < stack_a->data[stack_a->top])
				sa(stack_a);
		}
	}
}

static void	small_sort_b(t_stack * stack_a, t_stack *stack_b, int len)
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
		while (issorted_from_top(stack_b, 3))
		{
			if (stack_b->data[stack_b->top - 1] > stack_b->data[stack_b->top])
				cnt += ra(stack_b);
			if (stack_b->data[stack_b->top - 1] > stack_b->data[stack_b->top])
				sa(stack_b);
			if (cnt--)
				rra(stack_b);
			if (stack_b->data[stack_b->top - 1] > stack_b->data[stack_b->top])
				sa(stack_b);
		}
	}
}

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

void	ft_quicksort(t_stack *stack_a, t_stack *stack_b)
{
	int cnt_pa;
	int cnt_pb;

	cnt_pb = 0;
	if (stack_a->curr_cnt < 4)
		small_sort(stack_a, stack_a->curr_cnt);
	// else if (stack_a->curr_cnt < 6)
	// {
	// 	pb(stack_a, stack_b);
	// 	pb(stack_a, stack_b);
	// 	small_sort(stack_a, 3);
	// 	small_sort_b(stack_a, stack_b, 2);
	// }
	else
	{
		if (!issorted_bt(stack_a))
			cnt_pb = quick_b(stack_a, stack_b, stack_a->curr_cnt);
		if (stack_b->curr_cnt != 0)
			quick_a(stack_a, stack_b, cnt_pb);
	}
}

int quick_b(t_stack *stack_a, t_stack *stack_b, int len)
{
	t_sort sort;

	init_sort(stack_a, &sort, len);
	if (sort.arr == NULL)
		return (FALSE);
	if (sort.len < 3)
		small_sort(stack_a, len);
	else
	{
		while (len--)
		{
			if (stack_a->data[stack_a->top] < sort.p2)
			{
				sort.pb += pb(stack_a, stack_b);
				if (stack_b->data[stack_b->top] >= sort.p1 && \
				stack_b->data[stack_b->top] < sort.p2)
					sort.rb += rb(stack_b);
			}
			else
				sort.ra += ra(stack_a);
		}
		oper_rrr(stack_a, stack_b, sort);
		quick_b(stack_a, stack_b, sort.ra);
		quick_a(stack_a, stack_b, sort.rb);
		quick_a(stack_a, stack_b, sort.pb - sort.rb);
	}
	free(sort.arr);
	return (sort.pb);
}

int	quick_a(t_stack *stack_a, t_stack *stack_b, int len)
{
	t_sort sort;

	init_sort(stack_b, &sort, len);
	if (sort.arr == NULL)
		return (FALSE);
	if (sort.len < 3)
		small_sort_b(stack_a, stack_b, len);
	else
	{
		while (len-- && sort.len > 2)
		{
			if (stack_b->data[stack_b->top] >= sort.p1)
			{
				sort.pa += pa(stack_a, stack_b);
				if (stack_a->data[stack_a->top] < sort.p2 && \
				stack_a->data[stack_a->top] >= sort.p1)
					sort.ra += ra(stack_a);
			}	
				
			else
				sort.rb += rb(stack_b);
		}
		quick_b(stack_a, stack_b, sort.pa - sort.ra);
		oper_rrr(stack_a, stack_b, sort);
		quick_b(stack_a, stack_b, sort.pa - sort.ra);
		quick_a(stack_a, stack_b, sort.rb);
	}
	free(sort.arr);
	return (sort.pa);
}