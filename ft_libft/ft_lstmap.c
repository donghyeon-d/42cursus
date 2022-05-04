/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:50:23 by dongchoi          #+#    #+#             */
/*   Updated: 2022/03/19 11:14:09 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*temp;

	result = ft_lstnew(f(lst->content));
	if (result == 0)
		return (0);
	temp = result;
	lst = lst->next;
	while (lst)
	{
		temp->next = ft_lstnew(f(lst->content));
		if (temp->next == 0)
		{
			ft_lstclear(&result, del);
			return (0);
		}
		temp = temp->next;
		lst = lst->next;
	}
	return (result);
}
