#include <stdlib.h>
#include "pushswap.h"

void	rra(t_l_stack *stack_a)
{
	t_l_stack_node	*temp;

	if (stack_a->currentcount < 2)
		return ;
	temp = stack_a->bottom;
	temp->nextnode = stack_a->top;
	stack_a->top = temp;
	temp = stack_a->top;
	while (temp->nextnode != NULL)
		temp = temp->nextnode;
	stack_a->bottom = temp;
}

void	rrb(t_l_stack *stack_b)
{
	t_l_stack_node	*temp;

	if (stack_b->currentcount < 2)
		return ;
	temp = stack_b->bottom;
	temp->nextnode = stack_b->top;
	stack_b->top = temp;
	temp = stack_b->top;
	while (temp->nextnode != NULL)
		temp = temp->nextnode;
	stack_b->bottom = temp;
}

void	rrr(t_l_stack *stack_a, t_l_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}