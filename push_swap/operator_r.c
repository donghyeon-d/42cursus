#include <unistd.h>
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
	write(1, "ra\n", 3);
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
	write(1, "rb\n", 3);
}

void	rr(t_l_stack *stack_a, t_l_stack *stack_b)
{
	t_l_stack_node	*temp;

	if (stack_b->currentcount < 2 || stack_a->currentcount < 2)
		return ;
	temp = stack_b->top;
	stack_b->top = temp->nextnode;
	stack_b->bottom->nextnode = temp;
	stack_b->bottom = temp;
	temp = stack_a->top;
	stack_a->top = temp->nextnode;
	stack_a->bottom->nextnode = temp;
	stack_a->bottom = temp;
	write(1, "rr\n", 3);
}