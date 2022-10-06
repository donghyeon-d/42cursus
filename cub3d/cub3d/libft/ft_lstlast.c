/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choidongd <choidongd@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:11:42 by dongchoi          #+#    #+#             */
/*   Updated: 2022/09/20 17:47:25 by choidongd        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lastlist;

	if (lst == NULL)
		return (NULL);
	lastlist = lst;
	while (lastlist->next != 0)
		lastlist = lastlist->next;
	return (lastlist);
}
