/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:04:44 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/08 20:01:17 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.c"
#include "checker.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && i < n && s1[i] == s2[i])
		i++;
	if (i == n)
		i--;
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}


int	error_check(char *command)
{
	int	ret;

	ret = 1;
	if (ft_strncmp(command, "sa", 2) == 0 || \
	ft_strncmp(command, "sb", 2) == 0 || \
	ft_strncmp(command, "ss", 2) == 0 || \
	ft_strncmp(command, "pa", 2) == 0 || \
	ft_strncmp(command, "pb", 2) == 0 || \
	ft_strncmp(command, "ra", 2) == 0 || \
	ft_strncmp(command, "rb", 2) == 0 || \
	ft_strncmp(command, "rr", 2) == 0 || \
	ft_strncmp(command, "rra", 3) == 0 || \
	ft_strncmp(command, "rrb", 3) == 0 || \
	ft_strncmp(command, "rrr", 3) == 0)
		ret = 0;
	else if (ft_strncmp(command, "Error\n", 6) == 0)
		ret = 1;
	else
		ret = 1;
	return (ret);
}

void	excute_command(t_stack *stack_a, t_stack *stack_b,char *command)
{
	if (ft_strncmp(command, "sa", 2) == 0)
		sa(stack_a);
	else if (ft_strncmp(command, "sb", 2) == 0)
		sb(stack_b);
	else if (ft_strncmp(command, "ss", 2) == 0)
		ss(stack_a, stack_b);
	else if (ft_strncmp(command, "pa", 2) == 0)
		pa(stack_a, stack_b);
	else if (ft_strncmp(command, "pb", 2) == 0)
		pb(stack_a, stack_b);
	else if (ft_strncmp(command, "ra", 2) == 0)
		ra(stack_a);
	else if (ft_strncmp(command, "rb", 2) == 0)
		rb(stack_b);
	else if (ft_strncmp(command, "rra", 3) == 0)
		rra(stack_a);
	else if (ft_strncmp(command, "rrb", 3) == 0)
		rrb(stack_b);
	else if (ft_strncmp(command, "rrr", 3) == 0)
		rrr(stack_a, stack_b);
	else if (ft_strncmp(command, "rr", 2) == 0)
		rr(stack_a, stack_b);
}

int	checker(t_stack *stack_a, t_stack *stack_b, char *command)
{
	while (command != NULL)
	{
		if (error_check(command) == 1)
		{
			free(command);
			return (0);
		}
		excute_command(stack_a, stack_b, command);
		free(command);
		command = get_next_line(0);
	}
	if (isascend_from_top(stack_a, stack_a->curr_cnt) && stack_b->curr_cnt == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (1);
}

int main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*argument;//argv int array (not sorted) 
	int		count;
	char	*command;

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
	command = get_next_line(0);
	checker(stack_a, stack_b, command);
	del_stack(stack_a);
	del_stack(stack_b);
	free(argument);
	return (0);
}