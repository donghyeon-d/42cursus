/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ca.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:54:29 by dongchoi          #+#    #+#             */
/*   Updated: 2022/05/30 19:32:27 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_stack_ac	*init_stack_ac(int maxcount)
{
	t_stack_ac *newstack;

	if (maxcount <= 0)
		return (NULL);
	newstack = malloc(sizeof(t_stack_ac));
	if (newstack == NULL)
		return (NULL);
	newstack->data = malloc(sizeof(int) * maxcount);
	if (newstack->data == NULL)
	{
		free(newstack);
		return (NULL);
	}
	newstack->maxcount = maxcount;
	newstack->currentcount = 0;
	newstack->top_idx = 0;
	newstack->bottom_idx = 0;
	return (newstack);
}

int			push_stack_ac(t_stack_ac *pstack, int data)
{
	if (pstack == NULL || pstack->maxcount == pstack->currentcount)
		return (FALSE);
	if (newstack->currentcount == 0)
	{
		(newstack->data)[0] = data;
		newstack->top_idx = 0;
		newstack->bottom_idx = 0;
	}
	else
	{
		newstack->top_idx = (newstack->top_idx + 1) % newstack->maxcount;
		(newstack->data)[top_idx] = data;
	}
	newstack->currentcount++;
	return (TRUE);
}

int			pop_stack_ac(t_stack_ac *pstack)
{
	int	data;

	if (pstack == NULL || pstack->currentcount == 0)
		return (FALSE);
	data = (pstack->data)[pstack->top_idx];
	
}


// int			peak_stack_ac(t_stack_ac *pstack);
