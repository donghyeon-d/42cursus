/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:30:16 by dongchoi          #+#    #+#             */
/*   Updated: 2022/05/30 21:04:35 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# define TRUE 1
# define FALSE 0

// typedef struct s_stack_ac
// {
// 	int	maxcount;
// 	int	currentcount;
// 	int	top_idx;
// 	int	bottom_idx;
// 	int	*data;
// }	t_stack_ac;

// t_stack_ac	*init_stack_ac(int maxcount);
// int			push_stack_ac(t_stack_ac *pstack, int data);
// int			pop_stack_ac(t_stack_ac *pstack);
// int			peak_stack_ac(t_stack_ac *pstack);



typedef struct s_l_stack_node
{
	int				data;
	struct s_l_stack_node	*nextnode;
}	t_l_stack_node;

typedef struct s_l_stack
{
	int				currentcount;
	t_l_stack_node	*top;
	t_l_stack_node	*bottom;
}	t_l_stack;

// struct
t_l_stack	*init_l_stack();
int			push_l_stack(t_l_stack *pstack, int data);
t_l_stack_node	*pop_l_stack(t_l_stack *pstack);
int			peak_l_stack(t_l_stack *pstack);
void remove_l_stack(t_l_stack *pstack);

// operator
void	sa(t_l_stack *stack_a);
void	sb(t_l_stack *stack_b);
void	ss(t_l_stack *stack_a, t_l_stack *stack_b);
void	pa(t_l_stack *stack_a, t_l_stack *stack_b);
void	pb(t_l_stack *stack_a, t_l_stack *stack_b);
void	ra(t_l_stack *stack_a);
void	rb(t_l_stack *stack_b);
void	rr(t_l_stack *stack_a, t_l_stack *stack_b);
void	rra(t_l_stack *stack_a);
void	rrb(t_l_stack *stack_b);
void	rrr(t_l_stack *stack_a, t_l_stack *stack_b);

// util
int	ft_strlen(char *str);
long long	ft_atoll(char *argv);

// main
void	error_exit(t_l_stack *stack_a, t_l_stack *stack_b);
int	*make_stack(t_l_stack *stack_a, t_l_stack *stack_b, int argc, char *argv[]);
int	issorted(t_l_stack *stack);

//sort
int	bubble_sort(t_l_stack *stack);
int select_sort(t_l_stack *stack_a, t_l_stack *stack_b);

#endif