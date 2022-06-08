/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makearray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:28:02 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/07 19:31:10 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "pushswap.h"

void	valid_list(t_list *list, long long arg)
{
	t_list	*node;

	if (list == NULL)
		list->error = 1;
	if (arg > INT_MAX || arg < INT_MIN)
		list->error = 1;
	node = list->next;
	while (node != NULL && list->error == 0)
	{
		if ((int)arg == node->data)
			list->error = 1;
		node = node->next;
	}
}

int	argv_to_list(t_list *list, int argc, char *argv[])
{
	int			i;
	int			j;
	long long	arg;
	char		**temp;

	i = argc;
	while (--i > 0)
	{
		temp = ft_split(argv[i], ' ');
		j = 0;
		while (temp[j])
			j++;
		if (temp[0] == NULL)
			j = 1;
		while (--j > -1)
		{
			arg = ft_atoll(temp[j]);
			valid_list(list, arg);
			if (!push_list(list, (int)arg) || list->error == 1)
				return (FALSE);
		}
		ft_wordfree(temp);
	}
	return (TRUE);
}

int	*list_to_array(t_list *list)
{
	int		*arr;
	int		i;
	t_list	*node;

	if (list->curr_cnt < 1)
		return (NULL);
	arr = malloc(sizeof(int) * list->curr_cnt);
	if (arr == NULL)
		return (NULL);
	i = 0;
	node = list->next;
	while (node)
	{
		arr[i++] = node->data;
		node = node->next;
	}
	return (arr);
}

int	*stack_to_array(t_stack *stack, int len)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * len);
	if (arr == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		arr[i] = stack->data[stack->top - i];
	bubble_sort(arr, len);
	return (arr);
}

int	*make_array(int *argc, char *argv[])
{
	t_list	*list;
	int		*arr;

	list = init_list();
	if (list == NULL)
		return (NULL);
	if (argv_to_list(list, *argc, argv) == FALSE)
	{
		del_list(list);
		if (list->error == 1)
			error_exit(NULL, NULL, NULL, 1);
		return (NULL);
	}
	*argc = list->curr_cnt;
	arr = list_to_array(list);
	del_list(list);
	if (arr == NULL)
		return (NULL);
	return (arr);
}
