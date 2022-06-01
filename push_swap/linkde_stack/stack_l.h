#ifndef PUSHSWAP_H
# define PUSHSWAP_H

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

struct
t_l_stack	*init_l_stack();
int			push_l_stack(t_l_stack *pstack, int data);
t_l_stack_node	*pop_l_stack(t_l_stack *pstack);
int			peak_l_stack(t_l_stack *pstack);
void remove_l_stack(t_l_stack *pstack);
t_stack	*init_stack(int max_cnt);
int		push_stack(t_stack *stack, int data);
int		pop_stack(t_stack *stack);
int		del_stack(t_stack *stack);

#endif