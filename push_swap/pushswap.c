/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:30:37 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/08 11:31:03 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "pushswap.h"
// #include "../ft_libft/libft.h"

void display_stack(t_stack *stack)
{
	int i;

	if (stack == NULL)
	{
		printf("stack is NULL\n");
		return ;
	}
	if (stack->curr_cnt == 0)
	{
		printf("stack is empty\n");
		return ;
	}
	i = stack->top;
	printf("max_cnt : %d\n", stack->max_cnt);
	printf("cur_cnt : %d\n", stack->curr_cnt);
	printf("top : %d\n", stack->top);
	printf("bottom : %d\n", stack->bottom);
	printf("Top to Bottom : ");
	while (i >= 0)
	{
		printf("%d -> ", stack->data[i--]);
	}
	printf("\n");
}

void	error_exit(t_stack *stack_a, t_stack *stack_b, int *arr, int error)
{
	if (error == 1)
		write(2, "Error\n", 6);
	if (stack_a != NULL)
		del_stack(stack_a);
	if (stack_b != NULL)
		del_stack(stack_b);
	if (arr != NULL)
		free(arr);
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int			*argument;//argv int array (not sorted) 
	int	count;

	if (argc < 2)
		return (0);
	count = argc;
	argument = make_array(&count, argv);
	if (argument == NULL)
		return (0);
	stack_a = init_stack(count);
	if (stack_a == NULL)
		error_exit(NULL, NULL, argument, 0);
	stack_b = init_stack(count);
	if (stack_b == NULL)
		error_exit(stack_a, NULL, argument, 0);
	arr_to_stack(argument, count, stack_a);
	bubble_sort(argument, count);
	// display_stack(stack_a);
	// printf("\n");
	ft_quicksort(stack_a, stack_b);
	// printf("\n");
	// display_stack(stack_a);
	// display_stack(stack_b);
	// printf("\n");
	del_stack(stack_a);
	del_stack(stack_b);
	free(argument);
	return (0);
}