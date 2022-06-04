/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:54:29 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/04 15:26:16 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "pushswap.h"

t_stack	*init_stack(int max_cnt)
{
	t_stack	*new_stack;

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

int	pop_stack(t_stack *stack)
{
	int	data;

	if (stack == NULL || stack->curr_cnt == 0)
		return (FALSE);
	data = stack->data[stack->top];
	stack->curr_cnt--;
	stack->top--;
	if (stack->curr_cnt == 0)
		stack->top = 0;
	return (data);
}

int	del_stack(t_stack *stack)
{
	if (stack == NULL)
		return (TRUE);
	if (stack->data != NULL)
		free(stack->data);
	free(stack);
	return (TRUE);
}

void	arr_to_stack(int *arr, int arr_len, t_stack *stack_a)
{
	int	i;

	i = 0;
	while (--arr_len >= i)
		push_stack(stack_a, arr[arr_len]);
}
