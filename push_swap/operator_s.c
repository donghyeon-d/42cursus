#include <unistd.h>
#include <stdlib.h>
#include "pushswap.h"

void	sa(t_stack *stack_a)
{
	int	data;

	if (stack_a == NULL || stack_a->curr_cnt < 2)
		return ;
	data = stack_a->data[stack_a->top];
	stack_a->data[stack_a->top] = stack_a->data[stack_a->top - 1];
	stack_a->data[stack_a->top - 1] = data;
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b)
{
	int	data;

	if (stack_b == NULL || stack_b->curr_cnt < 2)
		return ;
	data = stack_b->data[stack_b->top];
	stack_b->data[stack_b->top] = stack_b->data[stack_b->top - 1];
	stack_b->data[stack_b->top - 1] = data;
	write(1, "sa\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	int	data;

	if (stack_a == NULL || stack_a->curr_cnt < 2)
		return ;
	if (stack_b == NULL || stack_b->curr_cnt < 2)
		return ;
	data = stack_a->data[stack_a->top];
	stack_a->data[stack_a->top] = stack_a->data[stack_a->top - 1];
	stack_a->data[stack_a->top - 1] = data;
	data = stack_b->data[stack_b->top];
	stack_b->data[stack_b->top] = stack_b->data[stack_b->top - 1];
	stack_b->data[stack_b->top - 1] = data;
	write(1, "ss\n", 3);
}