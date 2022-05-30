#include "pushswap.h"
#include <stdio.h>

// int	bubble_sort(t_l_stack *stack)
// {
// 	if (stack == 0)
// 		return (0);
// 	while (!issorted(stack))
// 	{
// 		if (stack->top->data > stack->top->nextnode->data)
// 		sa(stack);
// 		ra(stack);
// 	}
// 	return (1);
// }

int select_sort(t_l_stack *stack_a, t_l_stack *stack_b)
{
	int	i;
	int	min;
	t_l_stack_node *node;

	if (stack_a == NULL || stack_b == NULL || issorted(stack_a))
		return (0);
	while (stack_a->currentcount != 0)
	{
		i = -1;
		min = 2147483647;
		node = stack_a->top;
		while (++i < stack_a->currentcount)
		{
			if (min > node->data)
				min = node->data;
			node = node->nextnode;
		}
		while (stack_a->top->data != min)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	while (stack_b->currentcount)
		pa(stack_a, stack_b);
	return (1);
}

void 

// int main()
// {
// 	t_l_stack *stack_a;
// 	t_l_stack *stack_b;

// 	stack_a = init_l_stack();
// 	stack_b = init_l_stack();

// 	push_l_stack(stack_a, 4);
// 	push_l_stack(stack_a, 1);
// 	push_l_stack(stack_a, 5);
// 	push_l_stack(stack_a, 3);

// 	select_sort(stack_a, stack_b);
	// printf("%d\n", issorted(stack_a));
// }