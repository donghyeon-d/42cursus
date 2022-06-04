/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:26:52 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/04 15:27:32 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pushswap.h"

t_list	*init_list(void)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	if (new_list == NULL)
		return (NULL);
	new_list->curr_cnt = 0;
	new_list->error = 0;
	new_list->data = 0;
	new_list->next = NULL;
	return (new_list);
}

int	push_list(t_list *list, int data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (FALSE);
	node->data = data;
	node->next = NULL;
	if (list->curr_cnt == 0)
		list->next = node;
	else
	{
		node->next = list->next;
		list->next = node;
	}
	list->curr_cnt++;
	return (TRUE);
}

void	del_list(t_list *list)
{
	t_list	*del;
	t_list	*tmp;

	tmp = list->next;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	free(list);
}
