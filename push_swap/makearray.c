#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "pushswap.h"
#include "../ft_libft/libft.h"

void	valid_list(t_list *list, long long arg)
{//중복, 인트 맞는지, 인트 범위 인지
	int	i;
	t_list *node;

	if (list == NULL)
		list->error = 1;
	if (arg > INT_MAX || arg < INT_MIN)
		list->error = 1;
	i = -1;
	node = list->next;
	while (node != NULL &&  list->error = 0)
	{
		if ((int)arg == node->data)
			list->error = 1;
		node = node->next;
	}
}

int	argv_to_list(t_list *list, int argc, char *argv[]) // list의 head에는 argv[1]
{
	int			i;
	int			j;
	int			k;
	long long	arg;
	char		**temp;

	i = argc;
	k = -1;
	while (--i > 0)
	{
		temp = ft_split(argv[i], ' ');
		j = 0;
		while(temp[j])
			j++;
		while (--j > -1)
		{
			arg = atoll(temp[j]);
			valid_list(list, arg);
			if (push_list(list, (int)arg) || list->error == 1);
				return (FALSE);
		}
	}
}

char *list_to_array(t_list *list)  // arr[0] =  argv[1]
{
	int		*arr;
	int		i;
	t_list	*node;

	if (list->curr_cnt < 1)
		return (NULL);
	arr = malloc(sizeof(int) * list->curr_cnt);
	if (arr == NUL)
	{
		del_list(list);
		return (NULL);
	}
	i = 0;
	node = list->next;
	while (node)
	{
		arr[i++] = node->data;
		node = node->next;
	}
	return (arr);
}

int	*make_array(int *argc, char *argv[])
{
	// list 만들어서 split 하기
	// argc 조정하기
	// array만들어서 list에 있는거 꺼내오기
	// list free
	t_list	*list;
	int		*arr;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	if (argv_to_list(list, argc, argv) == FALSE)
	{
		del_list(list);
		return (NULL);
	}
	*argc = list->curr_cnt;
	arr = list_to_array(list);
	if (arr == NUL)
		return (NULL);
	if (list->error == 1)
	{
		del_list(list);
		error_exit(NULL, NULL, 1)
	}
	return (arr);
}
