/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:30:37 by dongchoi          #+#    #+#             */
/*   Updated: 2022/05/31 20:34:59 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "pushswap.h"
#include "../ft_libft/libft.h"

void	error_exit(t_stack *stack_a, t_stack *stack_b, int error)
{
	if (error == 1)
		write(2, "Error\n", 6);
	if (stack_a != NULL)
		del_stack(stack_a);
	if (stack_b != NULL)
		del_stack(stack_b);
	exit(0);
}

// int	*make_stack(t_stack *stack_a, t_stack *stack_b, int argc, char *argv[])
// {
// 	int				i;
// 	int				*argument;
// 	long long		digit;
// 	t_l_stack_node	*temp;

// 	i = 0;
// 	argument = malloc(sizeof(int) * (argc - 1));
// 	if (argument == NULL)
// 		error_exit(stack_a, stack_b, 0);
// 	while (++i < argc)
// 	{
// 		digit = ft_atoll(argv[i]);
// 		if (digit < INT_MIN || digit > INT_MAX)
// 			error_exit(stack_a, stack_b, 1);
// 		temp = stack_a->top;
// 		while (temp != NULL)// && temp->nextnode != NULL)
// 		{
// 			if (temp->data == (int)digit)
// 				error_exit(stack_a, stack_b, 1);
// 			temp = temp->nextnode;
// 		}
// 		push_l_stack(stack_a, (int)digit);
// 		argument[i - 1] = digit;
// 	}
// 	return (argument);
// }

// int	valid_arg(t_stack *stack_a, t_stack *stack_b, int *arg_arr, long long arg)
// {//중복, 인트 맞는지, 인트 범위 인지
// 	int	i;

// 	if (stack_a == NULL || stack_b == NULL)
// 		error_exit(stack_a, stack_b, arg_arr, 1);
// 	if (arg > INT_MAX || arg < INT_MIN)
// 		error_exit(stack_a, stack_b, arg_arr, 1);
// 	i = -1;
// 	while (++i < stack_a->curr_cnt)
// 	{
// 		if ((int)arg == stack_a->data[i])
// 			error_exit(stack_a, stack_b, arg_arr, 1);
// 	}
// 	return (TRUE);
// }

// int	*make_stack(t_stack *stack_a, t_stack *stack_b, int argc, char *argv[])
// {
// 	int			i;
// 	int			j;
// 	int			k;
// 	long long	arg;
// 	int			*arg_arr;
// 	char		**temp;

// 	i = argc;
// 	k = -1;
// 	arg_arr = malloc(sizeof(int) * (argc - 1));
// 	if (arg_arr == NULL)
// 		error_exit(stack_a, stack_b, 0, 0);
// 	while (--i > 0)
// 	{
// 		temp = ft_split(argv[i], ' ');
// 		j = 0;
// 		while(temp[j])
// 			j++;
// 		while (--j > -1)
// 		{
// 			arg = atoll(temp[j]);
// 			valid_arg(stack_a, stack_b, arg_arr, arg);
// 			arg_arr[++k] = atoll(temp[j]);
// 			push_stack(stack_a, (int)atoll(temp[j]));
// 		}
// 	}
// }

// void	*make_stack_re(t_stack *stack_a, t_stack *stack_b, int *arg_arr, char *argv)
// {
// 	if (arg == NULL)
// 		return ;
// 	make_stack_re(stack_a, stack_b, arg_arr, argv)
// }



int	issorted(t_l_stack *stack)
{
	int	i;

	if (stack == NULL)
		return (FALSE);
	i = -1;
	while (++i < stack->curr_cnt)
	{
		if (stack->data[i] <= stack->data[i + 1]
			return (FALSE);
	}
	return (TRUE);
}

int	main(int argc, char *argv[])
{
	t_l_stack	*stack_a;
	t_l_stack	*stack_b;
	int			*argument;//argv int array (not sorted) 

	if (argc < 2)
		return (0);
	argument = make_array(&argc, argv);
	if (argument == NULL)
		return (0);
	stack_a = init_stack(argc - 1);
	if (stack_a == NULL)
		error_exit(NULL, NULL, 0);
	stack_b = init_stack(argc - 1);
	if (stack_b == NULL)
		error_exit(stack_a, NULL, 0);
	arr_to_stack(argument, stack_a);
	argsort(argument, argc);
	ft_pushswap(stack_a, stack_b, argument, argc);
	// select_sort(stack_a, stack_b);
	return (0);
}