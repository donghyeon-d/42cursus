#include "pushswap.h"

void	ra(t_l_stack *stack_a)
{
	t_l_stack_node	*temp;

	if (stack_a->currentcount < 2)
		return ;
	temp = stack_a->top;
	stack_a->top = temp->nextnode;
	stack_a->bottom->nextnode = temp;
	stack_a->bottom = temp;
}

void	rb(t_l_stack *stack_b)
{
	t_l_stack_node	*temp;

	if (stack_b->currentcount < 2)
		return ;
	temp = stack_b->top;
	stack_b->top = temp->nextnode;
	stack_b->bottom->nextnode = temp;
	stack_b->bottom = temp;
}

void	rr(t_l_stack *stack_a, t_l_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}