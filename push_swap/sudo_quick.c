quick_sort(stack_a, stack_b, len)
{
	int cnt_pa;
	int cnt_pb;

	cnt_pb = 0
	if (stack_a->curr_cnt < 4)
		small_sort
	else if (stack_a->curr_cnt < 6)
	{
		pb
		pb
		small_sort_b
		small_sort
	}
	else
	{
		if (!issorted(stack_a), stack_a->curr_cnt)
			cnt_pb = quick_b(stack_a, stack_b, len);
		if (stack_b->curr_cnt != 0)
			quick_a(stack_a, stack_b, cnt_pb)
	}
}

int quick_b(t_stack *stack_a, t_stack *stack_b, int len)
{
	어레이 만들기
	피벗 설정
	while (len)
		피벗에 따라 3등분으로 쪼개서 넘겨주기
	if (ra != 0 || rb != 0)
		rrr
	quick_b(stack_a, stack_b, ra만큼);
	quick_a(stack_a, stack_b, rb만큼);
	quick_a(stack_a, stack_b, pb - rb만큼);
	free(어레이)
	return (pb)
}

int	quick_a(t_stack *stack_a, t_stack *stack_b, int len)// len = qb하면서 pa한 횟수
{
	어레이 만들기
	피벗 설정
	while(len)
		피벗에 따라 3등분으로 쪼개서 넘겨주기
	quick_b(stack_a, stack_b, pa - ra만큼);
	rrr
	quick_b(stack_a, stack_b, ra만큼);
	quick_a(stack_a, stack_b, rb만큼);
	return(pa);
}