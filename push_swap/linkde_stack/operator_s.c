#include <unistd.h>
#include <stdlib.h>
#include "pushswap.h"

void	sa(t_l_stack *stack_a)
{
	t_l_stack_node *temp;

	if (stack_a == NULL || stack_a->currentcount < 2)
		return ;
	temp = stack_a->top;
	stack_a->top = temp->nextnode;
	temp->nextnode = stack_a->top->nextnode;
	stack_a->top->nextnode = temp;
	write(1, "sa\n", 3);
}

void	sb(t_l_stack *stack_b)
{
	t_l_stack_node *temp;

	if (stack_b == NULL || stack_b->currentcount < 2)
		return ;
	temp = stack_b->top;
	stack_b->top = temp->nextnode;
	temp->nextnode = stack_b->top->nextnode;
	stack_b->top->nextnode = temp;
	write(1, "sb\n", 3);
}

void	ss(t_l_stack *stack_a, t_l_stack *stack_b)
{
	t_l_stack_node *temp;

	if (stack_a == NULL || stack_a->currentcount < 2)
		return ;
	if (stack_b == NULL || stack_b->currentcount < 2)
		return ;
	temp = stack_a->top;
	stack_a->top = temp->nextnode;
	temp->nextnode = stack_a->top->nextnode;
	stack_a->top->nextnode = temp;
	temp = stack_b->top;
	stack_b->top = temp->nextnode;
	temp->nextnode = stack_b->top->nextnode;
	stack_b->top->nextnode = temp;
	write(1, "ss\n", 3);
}