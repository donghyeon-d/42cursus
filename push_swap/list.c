#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "pushswap.h"
#include "../ft_libft/libft.h"

t_list	*init_list()
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	if (new_list == NULL)
		return (NULL);
	new_list->curr_cnt = 0;
	new_list->error = 0;
	new_list->data = 0;
	new_list->next = NULL;
}

int		push_list(t_list *list, int data)
{
	t_list	*node;
	t_list	*tmp;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (FALSE);
	node->data = data;
	node->next = NULL;
	if (list->curr_cnt == 0)
		node->next = node;
	else
	{
		node->next = list->next;
		list->next = node;
	}
	list->curr_cnt++;2
	return (TRUE);
}

void del_list(t_list *list)
{
	t_list *del;
	t_list *tmp;

	tmp = list->next;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	free(list);
}