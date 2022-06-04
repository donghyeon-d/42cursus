#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "pushswap.h"

static int	quick_b(t_stack *stack_a, t_stack *stack_b, int len);
static int	quick_a(t_stack *stack_a, t_stack *stack_b, int len);
static void	small_sort(t_stack *stack_a, int len);
static int	small_sort_b(t_stack * stack_a, t_stack *stack_b, int len);

int is_in_array(int *arr, int len, int data)
{
    while (--len)
    {
        if (arr[len] == data)
            return (TRUE);
    }
    return (FALSE);
}

int quick_b(t_stack *stack_a, t_stack *stack_b, int len) // len은 넘겨줄 개수
{
    int	*curr_arr;
	int	p1;
	int	p2;
	int count;
    int curr_last;

    count = 0;
    if (stack_a->curr_cnt < 4)
		return (small_sort(stack_a, stack_a->curr_cnt));
    curr_arr = stack_to_array(stack_a, stack_a->curr_cnt);
    if (curr_arr == NULL)
        error_exit(stack_a, stack_b, NULL, 0);
	p1 = curr_arr[(stack_a->top + 1) / 3];
	p2 = curr_arr[(stack_a->top + 1) * 2 / 3];
    curr_last = curr_arr[stack_a->curr_cnt];
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
    while (stack_a->data[0] > curr_last || stack_b->data[0] > curr_last)// curr_arr[last] 기준으로 가야할듯
        oper_rra(stack_a, stack_b, curr_last);
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
            rb(stack_b);
        }
        else// p2 보다 큰 값
            count += pb(stack_a, stack_b);
    }
    free(curr_arr);
    // 여기서 재귀
    while (stack_a->data[0] > curr_last || stack_b->data[0] > curr_last)
        oper_rra(stack_a, stack_b, curr_last);
    return (count);
}

