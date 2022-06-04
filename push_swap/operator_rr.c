#include <unistd.h>
#include <stdlib.h>
#include "pushswap.h"

void	rra(t_stack *stack_a)
{
	int	data;
	int	i;

	if (stack_a == NULL)
		return ;
	if (stack_a->curr_cnt > 1)
	{
		data = stack_a->data[stack_a->bottom];
		i = -1;
		while (++i < stack_a->curr_cnt - 1)
			stack_a->data[i] = stack_a->data[i + 1];
		stack_a->data[stack_a->top] = data;
	}
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b)
{
	int	data;
	int	i;
	if (stack_b == NULL)
		return ;
	if (stack_b->curr_cnt > 1)
	{
		data = stack_b->data[stack_b->bottom];
		i = -1;
		while (++i < stack_b->curr_cnt - 1)
			stack_b->data[i] = stack_b->data[i + 1];
		stack_b->data[stack_b->top] = data;
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
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
}

void	oper_rra(t_stack *stack_a, t_stack *stack_b, int criteria)
{
	if (stack_a->data[0] > criteria && stack_b->data[0] > criteria)
		rrr(stack_a, stack_b);
	else if (stack_a->data[0] > criteria && stack_b->data[0] <= criteria)
		rra(stack_a);
	else if (stack_a->data[0] <= criteria && stack_b->data[0] > criteria)
		rrb(stack_b);
}