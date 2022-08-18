#include "stack.h"
#include <stdlib.h>

t_stack	*create_stack(void)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (new_stack == NULL)
		exit(1);

	new_stack->curr_cnt = 0;
	new_stack->top = NULL;
	return (new_stack);
}

int push_stack(t_stack	*stack, char data)
{
	t_stack_node	*new_node;

	if (stack == NULL)
		exit(1);
	new_node = malloc(sizeof(t_stack_node));
	if (new_node == NULL)
		exit(1);
	new_node->data = data;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->curr_cnt++;
	return (TRUE);
}

int	remove_top(t_stack* stack)
{
	t_stack_node	*del;

	if (stack == NULL || stack->curr_cnt == 0)
		return (FALSE);
	del = stack->top;
	if (stack->curr_cnt == 1)
		stack->top = NULL;
	else
		stack->top = stack->top->next;
	free(del);
	stack->curr_cnt--;
	return (TRUE);
}

int	remove_stack(t_stack **stack)
{
	t_stack_node	*node;
	t_stack_node	*del;

	if (*stack == NULL)
		return (FALSE);
	if ((*stack)->curr_cnt == 0)
		free(*stack);
	if ((*stack)->curr_cnt > 0)
	{
		del = (*stack)->top;
		node = del;
		while (node != NULL)
		{
			node = node->next;
			free(del);
		}
	}
	free(*stack);
	stack = NULL;

}

void display_stack(t_stack	*stack)
{
	t_stack_node	*node;
	int			position;

	if (stack == NULL)
	{
		printf("LinkedStack is NULL\n");
		return ;
	}
	else if (stack->curr_cnt == 0)
	{
		printf("LinkedStack is empty\n");
		return ;
	}
	node = stack->top;
	position = 0;
	while (node)
	{
		printf("LinkedStack[%d] : %c\n", position, node->data);
		node = node->next;
        position++;
	}
}
