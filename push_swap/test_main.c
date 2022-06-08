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


/* ------------------------------------------------*/
/* make array.c */

int main()
{
	t_stack *a;
	t_stack *b;

	a = init_stack(10);
	b = init_stack(10);
	push_stack(a, 10);
	push_stack(a, 2);
	push_stack(a, 3);
	push_stack(a, -5);
	push_stack(a, 9);
	// push_stack(a, 1);
	// push_stack(a, 0);
	// push_stack(a, -7);
	// push_stack(a, -10);
	// push_stack(a, -1);

	ft_quicksort(a, b, 10);
	// printf("%d", issorted(a);
}


/* ------------------------------------------------*/
/* push_swap */


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



int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int			*argument;//argv int array (not sorted) 
	int	count;

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
	// display_stack(stack_a);
	// printf("\n");
	// ft_quicksort(stack_a, stack_b);
	if (quicksort(stack_a, stack_b) != 0)
		error_exit(stack_a, stack_b, argument, 1);
	// printf("\n");
	// display_stack(stack_a);
	// display_stack(stack_b);
	// printf("\n");
	del_stack(stack_a);
	del_stack(stack_b);
	free(argument);
	// system("leaks push_swap");
	return (0);
}