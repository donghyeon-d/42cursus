#ifndef _STACK_H_
#define _STACK_H_

typedef struct s_stack_node
{
	char data;
	struct s_stack_node* next;
} t_stack_node;

typedef struct s_stack
{
	int curr_cnt;
	t_stack_node* top;
} t_stack;

t_stack* creat_stack();
int push_stack(t_stack* stack, char data);
int	remove_top(t_stack* stack);
int	remove_stack(t_stack **stack);
void display_stack(t_stack	*stack);

#endif

#ifndef _COMMON_DEF_
#define _COMMON_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif
