/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:30:37 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/02 14:37:51 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "pushswap.h"
// #include "../ft_libft/libft.h"

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

// int	main(int argc, char *argv[])
// {
// 	t_l_stack	*stack_a;
// 	t_l_stack	*stack_b;
// 	int			*argument;//argv int array (not sorted) 

// 	if (argc < 2)
// 		return (0);
// 	argument = make_array(&argc, argv);
// 	if (argument == NULL)
// 		return (0);
// 	stack_a = init_stack(argc - 1);
// 	if (stack_a == NULL)
// 		error_exit(NULL, NULL, 0);
// 	stack_b = init_stack(argc - 1);
// 	if (stack_b == NULL)
// 		error_exit(stack_a, NULL, 0);
// 	arr_to_stack(argument, stack_a);
// 	argsort(argument, argc);
// 	ft_quicksort(stack_a, stack_b, stack_a->curr_cnt);
// 	error_exit(stack_a, stack_b, 0);	
// 	return (0);
// }