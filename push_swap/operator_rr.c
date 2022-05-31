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
	if (stack_a == NULL)
		return ;
	if (stack_b->curr_cnt > 1)
	{
		data = stack_b->data[stack_b->bottom];
		i = -1;
		while (++i < stack_b->curr_cnt - 1)
			stack_b->data[i] = stack_b->data[i + 1];
		stack_b->data[stack_b->top] = data;
	}
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	int	data;
	int	i;

	if (stack_a != NULL && stack_a->curr_cnt > 1)
	{
		data = stack_a->data[stack_a->bottom];
		i = -1;
		while (++i < stack_a->curr_cnt - 1)
			stack_a->data[i] = stack_a->data[i + 1];
		stack_a->data[stack_a->top] = data;
	}
	if (stack_b != NULL && stack_b->curr_cnt > 1)
	{
		data = stack_b->data[stack_b->bottom];
		i = -1;
		while (++i < stack_b->curr_cnt - 1)
			stack_b->data[i] = stack_b->data[i + 1];
		stack_b->data[stack_b->top] = data;
	}
	if (stack_a != NULL || stack_b != NULL)
		write(1, "rrr\n", 4);
}