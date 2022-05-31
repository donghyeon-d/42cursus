/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:54:29 by dongchoi          #+#    #+#             */
/*   Updated: 2022/05/31 20:31:38 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_stack	*init_stack(int max_cnt)
{
	t_stack *new_stack;

	if (max_cnt <= 0)
		return (NULL);
	new_stack = malloc(sizeof(t_stack));
	if (new_stack == NULL)
		return (NULL);
	new_stack->data = malloc(sizeof(int) * max_cnt);
	if (new_stack->data == NULL)
	{
		free(new_stack);
		return (NULL);
	}
	new_stack->max_cnt = max_cnt;
	new_stack->curr_cnt = 0;
	new_stack->top = 0;
	new_stack->bottom = 0;
	return (new_stack);
}

int	push_stack(t_stack *stack, int data)
{
	if (stack == NULL || stack->max_cnt == stack->curr_cnt)
		return (FALSE);
	if (stack->curr_cnt > 0)
		stack->top++;
	(stack->data)[stack->top] = data;
	stack->curr_cnt++;
	return (TRUE);
}

int			pop_stack(t_stack *stack)
{
	int	data;

	if (stack == NULL || stack->curr_cnt == 0)
		return (FALSE);
	data = stack->data[top];
	stack->top--;
	data = (stack->data)[stack->top];
}

int	del_stack(t_stack *stack)
{
	if (stack == NULL)
		return (TRUE);
	if (stack->data != NULL)
		free(stack->data);
	free(stack);
}

void arr_to_stack(int *arr, t_stack *stack_a)
{
	int	i;

	i = stack_a->max_cnt;
	while (--i >= 0)
		push_stack(stack_a, arr[i]);
}