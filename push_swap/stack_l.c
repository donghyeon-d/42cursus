#include <stdlib.h>
#include "pushswap.h"

t_l_stack	*init_l_stack()
{
	t_l_stack	*newstack;

	newstack = malloc(sizeof(t_l_stack));
	if (newstack == NULL)
		return (NULL);
	newstack->currentcount = 0;
	newstack->top = NULL;
	newstack->bottom = NULL;
	return (newstack);
}

int			push_l_stack(t_l_stack *pstack, int data)
{
	t_l_stack_node	*newnode;

	if (pstack == NULL)
		return (FALSE);
	newnode = malloc(sizeof(t_l_stack_node));
	if (newnode == NULL)
		return (FALSE);
	newnode->data = data;
	newnode->nextnode = NULL;
	if (pstack->currentcount == 0)
	{
		pstack->top = newnode;
		pstack->bottom = newnode;
	}
	else
	{
		newnode->nextnode = pstack->top;
		pstack->top = newnode;
	}
	pstack->currentcount++;
	return (TRUE);
}

t_l_stack_node	*pop_l_stack(t_l_stack *pstack)
{
	t_l_stack_node	*popnode;

	if (pstack == NULL || pstack->currentcount == 0)
		return(FALSE);
	popnode = pstack->top;
	if (pstack->currentcount == 1)
	{
		pstack->top = NULL;
		pstack->bottom = NULL;
	}
	else
		pstack->top = pstack->top->nextnode;
	pstack->currentcount--;
	return (popnode);
}

int	peak_l_stack(t_l_stack *pstack) // data 에 음수도 있으면 어떻게 해야되지...
{
	if (pstack == NULL || pstack->currentcount == 0)
		return (FALSE);
	return (pstack->top->data);
}

void remove_l_stack(t_l_stack *pstack)
{
	t_l_stack_node	*del;
	t_l_stack_node	*temp;

	if (pstack == NULL)
		return ;
	temp = pstack->top;
	del = temp;
	while (temp != NULL)
	{
		temp = temp->nextnode;
		free(del);
		del = temp;
	}
}