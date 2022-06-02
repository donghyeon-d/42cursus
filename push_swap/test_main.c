#include <stdio.h>
#include <stdlib.h>

/* ------------------------------------------------*/
/* stack.c */
void display_stack(t_stack *stack)
{
	int i;

	if (stack == NULL)
	{
		printf("stack is NULL\n");
		return ;
	}
	if (stack->curr_cnt == 0)
	{
		printf("stack is empty\n");
		return ;
	}
	i = stack->top;
	printf("max_cnt : %d\n", stack->max_cnt);
	printf("cur_cnt : %d\n", stack->curr_cnt);
	printf("top : %d\n", stack->top);
	printf("bottom : %d\n", stack->bottom);
	printf("Top to Bottom : ");
	while (i >= 0)
	{
		printf("%d -> ", stack->data[i--]);
	}
	printf("\n");
}

int main()
{
	t_stack *stack;
	int data;

	stack = init_stack(5);
	push_stack(stack, 10);
	push_stack(stack, -5);
	push_stack(stack, 0);
	push_stack(stack, 5);
	push_stack(stack, -10);

	display_stack(stack);
	printf("\n\n");

	data = pop_stack(stack);
	printf("pop data : %d\n", data);
	data = pop_stack(stack);
	printf("pop data : %d\n", data);
	data = pop_stack(stack);
	printf("pop data : %d\n", data);
	data = pop_stack(stack);
	printf("pop data : %d\n", data);
	data = pop_stack(stack);
	printf("pop data : %d\n", data);
	display_stack(stack);
	printf("\n\n");

	int n = 3;
	int arr[n];
	// arr = malloc(sizeof(int) * 5);
	arr[0] = 10;
	arr[1] = -5;
	arr[2] = 0;
	arr[3] = 5;
	arr[4] = -10;
	int len = (int)(sizeof(arr) / sizeof(int));
	arr_to_stack(arr, len, stack);
	display_stack(stack);



	// del_stack(stack);
	// stack = NULL;
	// system("leaks a.out");
}

/* ------------------------------------------------*/
/* list.c */
int main()
{
	void display_list(t_list *list)
{
	t_list *temp;

	if (list == NULL)
	{
		printf("list is NULL\n");
		return ;
	}
	if (list->next == NULL)
	{
		printf("list is empty\n");
		return ;
	}
	printf("curr_cnt : %d\n", list->curr_cnt);
	printf("data : %d\n", list->data);
	printf("error : %d\n", list->error);
	temp = list->next;
	while (temp)
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
}

int main()
{
	t_list *list;

	list = init_list();
	display_list(list);

	push_list(list, -5);
	push_list(list, 10);
	push_list(list, 15);
	push_list(list, 0);
	push_list(list, 5);
	display_list(list);
	del_list(list);
	list = NULL;
	system("leaks a.out");
}


/* ------------------------------------------------*/
/* sort.c */

int main()
{
	int arr[5] = {5, 2, 3, 1, 4};

	for(int i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	printf("\n\n");
	bubble_sort(arr, 5);
	for(int i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	printf("\n\n");
}


/* ------------------------------------------------*/
/* util.c */

int main()
{
	char **ar;
	long long digit;

	ar = (char **)malloc(sizeof(char *) * 5);
	for (int i = 0; i < 5; i++)
		ar[i] = (char *)malloc(sizeof(char) * 5);
	ar[0] = "+31";
	ar[1] = "-11";
	ar[2] = "0";
	ar[3] = "21474836474811";
	ar[4] = "-21474836474811";

	for (int j; j < 5; j++)
	{
		digit = ft_atoll(&ar[j][0]);
		printf("%lld\n", digit);
	}
	return (0);
}


/* ------------------------------------------------*/
/* make array.c */

int main(int argc, char *argv[])
{
	int	*arr;

	if (argc < 2)
		return (0);
	arr = make_array(&argc, argv);
	// printf("%p", arr);
		// printf("%d ", arr[0]);
	for (int i = 0; i < argc; i++)
		printf("%d ", arr[i]);
	free(arr);
	// system("leaks a.out");
}
