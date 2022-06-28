/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongchoi <dongchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:15:33 by dongchoi          #+#    #+#             */
/*   Updated: 2022/06/28 13:48:31 by dongchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*locate;

	if (s == 0)
		return (0);
	locate = (char *)s;
	while ((char)*locate != (char)c && *locate != '\0')
		locate++;
	if (*locate == '\0' && c != '\0')
		return (0);
	return (locate);
}
