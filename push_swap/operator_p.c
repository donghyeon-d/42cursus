#include <stdlib.h>
#include "pushswap.h"

void	pa(t_l_stack *stack_a, t_l_stack *stack_b)
{
	int	data;
	t_l_stack_node	*popnode;

	if  (stack_b == NULL || stack_b->currentcount == 0)
		return ;
	popnode = pop_l_stack(stack_b);
	data = popnode->data;
	push_l_stack(stack_a, data);
	free(popnode);
}

void	pb(t_l_stack *stack_a, t_l_stack *stack_b)
{
	int	data;
	t_l_stack_node	*popnode;

	if  (stack_a == NULL || stack_a->currentcount == 0)
		return ;
	popnode = pop_l_stack(stack_a);
	if (popnode == NULL)
		return ;
	data = popnode->data;
	push_l_stack(stack_b, data);
	free(popnode);
}