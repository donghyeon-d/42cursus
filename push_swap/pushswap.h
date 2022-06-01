/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:30:16 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/01 20:20:30 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# define TRUE 1
# define FALSE 0

typedef struct s_stack
{
	int	max_cnt;
	int	curr_cnt;
	int	top;
	int	bottom;
	int	*data;
}	t_stack;

typedef struct s_list
{
	int	curr_cnt;
	int	data;
	int error;
	struct s_list *next;
}	t_list;

t_stack	*init_stack(int maxcount);
int		push_stack(t_stack *stack, int data);
int		pop_stack(t_stack *stack);
int		del_stack(t_stack *stack);
void	arr_to_stack(int *arr, int arr_len, t_stack *stack_a);//arr 만들 때 정적으로 배열 만들어 줘야 함. 동적 할당 x // argv -> list -> array 할 때 make_array 함수에서 argc 바꿔주는데 그거 활용할 수 있을듯?!
void 	display_stack(t_stack *stack);

t_list	*init_list();
int		push_list(t_list *list, int data);
void 	del_list(t_list *list);

// operator
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
int		pa(t_stack *stack_a, t_stack *stack_b);
int		pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

// util
long long	ft_atoll(char *argv);

// main
void	error_exit(t_stack *stack_a, t_stack *stack_b, int error);

// make array
void	valid_list(t_list *list, long long arg);
int	argv_to_list(t_list *list, int argc, char *argv[]);
char *list_to_array(t_list *list);
int	*stack_to_array(t_stack *stack);
int	*make_array(int *argc, char *argv[]);

//sort 
int bubble_sort(int *arr, int len);// 오름차순 // [0]이 제일 작음
int	issorted(t_stack *stack);

void	ft_quicksort(t_stack *stack_a, t_stack *stack_b, int len);

#endif