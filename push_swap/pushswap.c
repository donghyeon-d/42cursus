/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:30:37 by dongchoi          #+#    #+#             */
/*   Updated: 2022/05/27 15:36:13 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "pushswap.h"

void	error_exit(int argc, char *argv[], t_l_stack *stack_a, t_l_stack *stack_b)
{
	write(2, "Error\n", 6);
	if (stack_a != NULL)
		remove_l_stack(stack_a);
	if (stack_b != NULL)
		remove_l_stack(stack_b);
	exit(0);
}

int	*make_stack(t_l_stack *stack_a, t_l_stack *stack_b, int argc, char *argv[])
{
	int				i;
	int				*argument;
	long long		digit;
	t_l_stack_node	*temp;

	i = 0;
	argument = malloc(sizeof(int) * (argc - 1));
	if (argument == NULL)
		error_exit(argc, argv, stack_a, stack_b);
	while (++i < argc)
	{
		digit = ft_atoll(argv[i]);
		if (digit < INT_MIN || digit > INT_MAX)
			error_exit(argc, argv, stack_a, stack_b);
		push_l_stack(stack_a, (int)digit);
		argument[i - 1] = digit;
		temp = stack_a->top;
		while (temp->nextnode != NULL)
		{
			if (temp->data == (int)digit)
				error_exit(argc, argv, stack_a, stack_b);
			temp = temp->nextnode;
		}
	}
	return (argument);
}

int	main(int argc, char *argv[])
{
	t_l_stack	*stack_a;
	t_l_stack	*stack_b;
	int			*argument;//argv int array (not sorted) 

	if (argc < 2)
		error_exit(NULL, NULL);
	stack_a = init_l_stack();
	if (stack_a == NULL)
		error_exit(NULL, NULL);
	stack_b = init_l_stack();
	if (stack_b == NULL)
		error_exit(stack_a, NULL);
	argument = make_stack(stack_a, stack_b, argc, argv); 
	
	// ft_pushswap(stack_a, stack_b);
}