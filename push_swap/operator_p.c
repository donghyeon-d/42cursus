/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:28:54 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/04 15:30:02 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "pushswap.h"

int	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	data;

	if (stack_b->curr_cnt == 0 || stack_a->max_cnt == stack_a->curr_cnt)
		return (0);
	data = pop_stack(stack_b);
	push_stack(stack_a, data);
	write(1, "pa\n", 3);
	return (1);
}

int	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	data;

	if (stack_a->curr_cnt == 0 || stack_b->max_cnt == stack_b->curr_cnt)
		return (0);
	data = pop_stack(stack_a);
	push_stack(stack_b, data);
	write(1, "pb\n", 3);
	return (1);
}
