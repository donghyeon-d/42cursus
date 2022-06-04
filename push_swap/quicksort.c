#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "pushswap.h"

static int	quick_b(t_stack *stack_a, t_stack *stack_b, int len);
static int	quick_a(t_stack *stack_a, t_stack *stack_b, int len);
static int	small_sort(t_stack *stack_a, int len);
static int	small_sort_b(t_stack * stack_a, t_stack *stack_b, int len);

// int is_in_array(int *arr, int len, int data)
// {
//     while (--len)
//     {
//         if (arr[len] == data)
//             return (TRUE);
//     }
//     return (FALSE);
// }

static int	small_sort(t_stack *stack_a, int len)
{
	int	cnt;

	cnt = 0;
	if (len < 2)
		return (cnt);
	if (len == 2)
	{
		if (stack_a->data[0] < stack_a->data[1])
			sa(stack_a);
		return (cnt);
	}
	if (len == 3)
	{
		while (stack_a->data[0] < stack_a->data[1] || stack_a->data[0] < stack_a->data[2])
			ra(stack_a);
		if (stack_a->data[1] < stack_a->data[2])
			sa(stack_a);
		return (cnt);
	}
	return (cnt);
}

static int	small_sort_b(t_stack * stack_a, t_stack *stack_b, int len)
{
	if (len < 2)
	{
		pa(stack_a, stack_b);
		return (1);
	}
	if (len == 2)
	{
		if (stack_b->data[0] > stack_b->data[1])
			sb(stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		return (2);
	}
	if (len == 3)
	{
		while (stack_b->data[0] > stack_b->data[1] || stack_b->data[0] > stack_b->data[2])
			rb(stack_b);
		if (stack_b->data[1] > stack_b->data[2])
			sb(stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		return (3);
	}
	return (0);
}

int quick_b(t_stack *stack_a, t_stack *stack_b, int len) // len은 넘겨줄 개수
{
    int	*curr_arr;
	int	p1;
	int	p2;
	int count;
    int curr_last;

    count = 0;
	if (issorted_bt(stack_a))
		return (0);
    if (stack_a->curr_cnt < 4)
		return (small_sort(stack_a, stack_a->curr_cnt));
    curr_arr = stack_to_array(stack_a, stack_a->curr_cnt);
    if (curr_arr == NULL)
        error_exit(stack_a, stack_b, NULL, 0);
	p1 = curr_arr[(stack_a->top + 1) / 3];
	p2 = curr_arr[(stack_a->top + 1) * 2 / 3];
    curr_last = curr_arr[stack_a->curr_cnt - 1];
    while (len--)
    {
        // b_to_a(stack_a, stack_b, p1, p2);
        if (stack_a->data[stack_a->top] <= p1)
            count += pb(stack_a, stack_b);
        else if (stack_a->data[stack_a->top] > p1 && stack_a->data[stack_a->top] <= p2)
        {
            count += pb(stack_a, stack_b);
            rb(stack_b);
        }
        else// p2 보다 큰 값
            ra(stack_a);
    }
    free(curr_arr);
    // 정렬되어 있으면 안하는 것도 괜찮을듯
    // while (stack_a->data[0] <= curr_last || stack_b->data[0] >= curr_arr[0])// curr_arr[last] 기준으로 가야할듯
	// {
	// 	if (oper_rra(stack_a, stack_b, curr_last, curr_arr[0]) == 0)
	// 		break ;
	// }
	printf("\n");
    return (count);
}

int	quick_a(t_stack *stack_a, t_stack *stack_b, int len)//from b to a // len = QA의 리턴값
{
    int	*curr_arr;
	int	p1;
	int	p2;
	int count;
    int curr_last;

    if (stack_b->curr_cnt < 4)
		return (small_sort_b(stack_a, stack_b, stack_b->curr_cnt));
    count = 0;
    curr_arr = stack_to_array(stack_b, len);
    if (curr_arr == NULL)
        error_exit(stack_a, stack_b, NULL, 0);
	p1 = curr_arr[len / 3];
	p2 = curr_arr[len * 2 / 3];
    curr_last = curr_arr[len - 1];
    while (len--)
    {
        if (stack_b->data[stack_b->top] <= p1)
            rb(stack_b);
        else if (stack_b->data[stack_b->top] > p1 && stack_b->data[stack_b->top] <= p2)
        {
            count += pa(stack_a, stack_b);
            ra(stack_a);
        }
        else// p2 보다 큰 값
            count += pa(stack_a, stack_b);
    }
    free(curr_arr);
    while (stack_a->data[0] <= curr_last || stack_b->data[0] >= curr_arr[0])
	{
		if (oper_rra(stack_a, stack_b, curr_last, curr_arr[0]) == 0)
			break ;
	}
	printf("\n");
    return (count);
}

int	ft_quicksort(t_stack *stack_a, t_stack *stack_b, int len)
{
	int	count_qa;
	int	count_qb;
	
	// if (stack_a->curr_cnt < 4)
	// 	return (small_sort(stack_a, stack_a->curr_cnt));
	// if (stack_b->curr_cnt < 4)
	// 	return (small_sort_b(stack_a, stack_b, stack_b->curr_cnt));
	// count_qa = 0;
	// count_qb = 0;
	count_qb = quick_b(stack_a, stack_b, stack_a->curr_cnt);
	if (count_qb == 0)
		count_qb = stack_b->curr_cnt;
	// display_stack(stack_a);
	// display_stack(stack_b);
	if (!issorted_bt(stack_a) && stack_a->curr_cnt > 1)
		ft_quicksort(stack_a, stack_b, stack_a->curr_cnt);
	count_qa = quick_a(stack_a, stack_b, count_qb);
	if (!issorted_bt(stack_a) && stack_b->curr_cnt > 0)
		ft_quicksort(stack_a, stack_b, stack_a->curr_cnt);
	return (1);
}
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

// int main()
// {
// 	t_stack *a = init_stack(10);
// 	t_stack *b = init_stack(10);
// 	push_stack(a, 2);
// 	push_stack(a, 1);
// 	push_stack(a, 3);
// 	push_stack(a, 6);
// 	push_stack(a, 5);
// 	push_stack(a, 7);
// 	push_stack(a, 0);
// 	push_stack(a, 9);
// 	push_stack(a, -5);
// 	push_stack(a, 10);

// 	display_stack(a);
// 	printf("\n");
// 	ft_quicksort(a,b, a->curr_cnt);
// 	display_stack(a);
// 	display_stack(b);
// 	printf("\n");
// }
₩