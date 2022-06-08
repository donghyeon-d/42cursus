/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:30:37 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/08 20:10:29 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pushswap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*argument;
	int		count;

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
	if (quicksort(stack_a, stack_b) != 0)
		error_exit(stack_a, stack_b, argument, 1);
	del_stack(stack_a);
	del_stack(stack_b);
	free(argument);
	return (0);
}
